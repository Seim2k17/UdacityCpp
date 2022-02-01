#include "linux_parser.h"

#include <dirent.h>
#include <unistd.h>

#include <algorithm>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include "format.h"
#include "process_details.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, version, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// DONE: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() 
{ 
  string line, topic, memory;
  double memTotal,memAvailable;
  
  std::ifstream filestream(kProcDirectory + kMeminfoFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      linestream >> topic >> memory;
      if (topic == "MemTotal:") {
        memTotal = std::atof(memory.c_str());
      }
      if (topic == "MemAvailable:") {
        memAvailable = std::atof(memory.c_str());
      }
    }
  }
  if(memAvailable != 0.0 && memTotal != 0.0)
  {
    return (memAvailable / memTotal); 
  }
  return 0.0;
}

// DONE: Read and return the system uptime
long LinuxParser::UpTime() {
  string uptime, idle;
  string line;
  std::ifstream stream(kProcDirectory + kUptimeFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> uptime >> idle;
  }
  return std::atol(uptime.c_str());
}

// DONE: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() { 
  // simple implementattion: we only read the first line, it contains aggregate CPU-information
  string line, value;
  std::vector<string> cpuValues;
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if (filestream.is_open()) {
    std::getline(filestream, line);
    std::istringstream linestream(line);
      while (linestream >> value) {
        // emplpace_back is cheaper and calls constructor inplace while push_back move/copied the value
        cpuValues.emplace_back(value);
      }
  }
  return cpuValues; 
}

// DONE: Read and return the total number of processes
int LinuxParser::TotalProcesses() { return LinuxParser::Pids().size(); }

// DONE: Read and return the number of running processes
int LinuxParser::RunningProcesses() {
  string line, topic, running;
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      linestream >> topic >> running;
      if (topic == "procs_running") {
        return std::atoi(running.c_str());
      }
    }
  }
  return 0;
}

ProcessDetails LinuxParser::parseProcess(int pid) {
  // only open and parse the pid/stat - file once
  std::vector<std::string> pTimeCnt;
  string time, line;
  std::ifstream filestream(kProcDirectory + std::to_string(pid) +
                           kStatFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      // get stuff into a iteratable thing
      while (linestream >> time) {
        pTimeCnt.push_back(time);
      }
    }
  }

  std::string processCommand = LinuxParser::Command(pid);
  std::string processram = LinuxParser::Ram(pid);
  std::string processUid = LinuxParser::Uid(pid);
  std::string processUser = LinuxParser::User(pid);
  std::string cpuUsage = LinuxParser::CpuUtilization(pTimeCnt);
  std::string processUptime = std::to_string(LinuxParser::UpTime(pTimeCnt));

  ProcessDetails details{pid};
  details.Command(processCommand);
  details.Ram(processram);
  details.UserId(processUid);
  details.User(processUser);
  details.UpTime(processUptime);
  details.CpuUtilization(cpuUsage);

  return details;
}

string LinuxParser::CpuUtilization(std::vector<std::string>& pTimes) {
  // fancy calculations from here:
  // https://stackoverflow.com/questions/16726779/how-do-i-get-the-total-cpu-usage-of-an-application-from-proc-pid-stat/16736599#16736599
  std::string utime, stime, cutime, cstime, starttime;
  std::string out = string("0.00");

  if (pTimes.size() > 0) {
    // float totalTime = std::stoi(pTimes.at(13)) + std::stoi(pTimes.at(14)) + std::stoi(pTimes.at(15))+ std::stoi(pTimes.at(16));
    float totalTime = std::stoi(pTimes.at(13)) + std::stoi(pTimes.at(14));

    if (totalTime == 0.00) {
      return out;
    }
    auto clock = sysconf(_SC_CLK_TCK);

    int timeInSec = LinuxParser::UpTime(pTimes); //upTime - (std::stoi(pTimes.at(21)) / clock);
    float usage = ((totalTime / clock) / timeInSec) * 100;

    out = std::to_string(usage);
  }

  return out;
}

// DONE: Read and return the command associated with a process
string LinuxParser::Command(int pid) {
  string command;
  string line;
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kCmdlineFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> command;
  }
  return command.c_str();
}
// check if a string is a integer number
auto isNumber = [](std::string s){
    return s.find_first_not_of("012345678") == std::string::npos;
};

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid) 
{ 

  string ram;
  string line, topic;
  string skip;
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatusFilename);

  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      linestream >> topic;
      // VmSize gives us VirtualMemory which is most probably more than the physical so i use VmRSS instead
      if(topic == "VmRSS:")
      {
        linestream >> ram;
        break;
      }
      else
      {
        linestream >> skip;
      }
    }
  }
  
  if(isNumber(ram))
  {
    return "N/A";
  }

  auto i = std::stoi(ram)/1024;
  stream.close();
  return std::to_string(i); 
}

// DONE: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) 
{ 
  string uid;
  string line, topic;
  string skip;
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatusFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      linestream >> topic;
      if(topic == "Uid:")
      {
        linestream >> uid;
        break;
      }
      else
      {
        linestream >> skip;
      }
    }
  }
  return uid.c_str();
}

// DONE: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) 
{ 
  std::string uid = LinuxParser::Uid(pid);
  //std::string uid{"65534"};
  string line, user, token;
  string skip;
  bool userSet = false;
  std::ifstream pwdStream("/etc/passwd");
  
  if (pwdStream.is_open()) {
    while (std::getline(pwdStream, line)) {
      
      std::istringstream linestream(line);
      userSet = false;
      while(std::getline(linestream,token,':'))
      {
        if(!userSet)
        {
          user = token;
          userSet=true;
        }
        
        if(token==uid)
        {
          return user;
        }
      }
    }
  }
  // some systems use other login methods like ldap - atm i don't know how to get these infos
  return string("N/A"); 
}

// DONE: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(std::vector<std::string>& pTimes) {

if (pTimes.size() > 0) {
  long upTime = LinuxParser::UpTime();
  auto clock = sysconf(_SC_CLK_TCK);

  long timeInsSecs = (upTime - std::stoi(pTimes.at(21)) / clock);//*100;
  return timeInsSecs;
}
  
  return 0;
}
