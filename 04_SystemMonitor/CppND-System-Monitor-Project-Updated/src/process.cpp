#include "process.h"
#include "linux_parser.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid)
{
  details = new ProcessDetails(pid);
  *details = LinuxParser::parseProcess(pid);
}

Process::~Process()
{
  delete details;
}

// TODO: Return this process's ID
int Process::Pid() 
{
   return details->Pid(); 
}

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() 
{
  return std::stof(details->CpuUtilization());  
}

// TODO: Return the command that generated this process
string Process::Command() 
{
  return details->Command(); 
}

// TODO: Return this process's memory utilization
string Process::Ram() 
{
  return details->Ram(); 
}

// TODO: Return the user (name) that generated this process
string Process::User() 
{
  return details->User(); 
}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() 
{ 
  return 0;  
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a [[maybe_unused]]) const {
  return true;
}