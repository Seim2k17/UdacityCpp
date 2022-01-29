#include "system.h"

#include <unistd.h>

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// REFINE: Return the system's CPU
Processor& System::Cpu() { return cpu_; }

void System::createProcess(int pid) {
  auto compare = [pid](Process p) { return p.Pid() == pid; };
  if (std::find_if(processes_.begin(), processes_.end(), compare) ==
      processes_.end()) {
    Process p(pid);
    // some processes don't have the VmSize-column in /proc/[pid]/status -file
    if(p.Ram() != "N/A")
    {
      processes_.push_back(p);
    }
    
    return;
  }
}

bool sortProcessesDescendingCpu(Process p1, Process p2) {
  //return (p1.User() < p2.User());
  return (p1.CpuUtilization() > p2.CpuUtilization());
  //return (p1 < p2);
}

// DONE: Return a container composed of the system's processes
vector<Process>& System::Processes() {
  std::vector<int> pids = LinuxParser::Pids();

  processes_.clear();
  
  for (const int pid : pids) {
    createProcess(pid);
  }

  std::sort(processes_.begin(), processes_.end(), sortProcessesDescendingCpu);
  return processes_;
}

// DONE: Return the system's kernel identifier (string)
std::string System::Kernel() { return LinuxParser::Kernel(); }

// DONE: Return the system's memory utilization
float System::MemoryUtilization() { 
  return LinuxParser::MemoryUtilization(); 
} 

// DONE: Return the operating system name
std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

// DONE: Return the number of processes actively running on the system
int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

// DONE: Return the total number of processes on the system
int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

// DONE: Return the number of seconds since the system started running
long int System::UpTime() { return LinuxParser::UpTime(); }