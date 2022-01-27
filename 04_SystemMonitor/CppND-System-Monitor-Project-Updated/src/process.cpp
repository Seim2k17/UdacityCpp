#include "process.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process_details.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) { details = LinuxParser::parseProcess(pid); }

// DONE: Return this process's ID
int Process::Pid() { return details.Pid(); }

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() { return std::stof(details.CpuUtilization()); }

// DONE: Return the command that generated this process
string Process::Command() { return details.Command(); }

// DONE: Return this process's memory utilization
string Process::Ram() { return details.Ram(); }

// DONE: Return the user (name) that generated this process
string Process::User() { return details.User(); }

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() { return std::stol(details.UpTime()); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a [[maybe_unused]] ) const {
  //return (a.CpuUtilization() > p2.CpuUtilization());
  return true;
}