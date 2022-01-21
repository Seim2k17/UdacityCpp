#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>

#include "process.h"
#include "process_details.h"
#include "processor.h"

class System {
 public:
  Processor& Cpu();                   // TODO: See src/system.cpp
  std::vector<Process>& Processes();  // DONE: See src/system.cpp
  float MemoryUtilization();          // TODO: See src/system.cpp
  long UpTime();                      // DONE: See src/system.cpp
  int TotalProcesses();               // DONE: See src/system.cpp
  int RunningProcesses();             // DONE: See src/system.cpp
  std::string Kernel();               // DONE: See src/system.cpp
  std::string OperatingSystem();      // DONE: See src/system.cpp

  // DONE: Define any necessary private members
 protected:
  void createProcess(int pid);

 private:
  Processor cpu_ = {};
  std::vector<Process> processes_ = {};
};

#endif