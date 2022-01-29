#include "processor.h"
#include "linux_parser.h"
#include <iostream>

Processor::Processor()
: prevUser(0)
, prevNice(0)
, prevSystem(0)
, prevIrq(0)
, prevSoftIrq(0)
, prevSteal(0)
, prevIowait(0)
{
}

// DONE: Return the aggregate CPU utilization
/** source: https://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in-percentage-in-linux
* 
* PrevIdle = previdle + previowait
* Idle = idle + iowait
* PrevNonIdle = prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal
* NonIdle = user + nice + system + irq + softirq + steal

* PrevTotal = PrevIdle + PrevNonIdle
* Total = Idle + NonIdle

* # differentiate: actual value minus the previous one
* totald = Total - PrevTotal
* idled = Idle - PrevIdle

* CPU_Percentage = (totald - idled)/totald
*/
float Processor::Utilization() {

  std::vector<std::string> values = LinuxParser::CpuUtilization();
  
  long prevIdleTotal = prevIdle + prevIowait;
  prevNonIdle = prevUser + prevNice + prevSystem + prevIrq + prevSoftIrq + prevSteal;

  user = std::atol(values.at(1).c_str());
  nice = std::atol(values.at(2).c_str());
  system = std::atol(values.at(3).c_str());
  idle = std::atol(values.at(4).c_str());
  iowait = std::atol(values.at(5).c_str());
  irq = std::atol(values.at(6).c_str());
  softIrq = std::atol(values.at(7).c_str());
  steal = std::atol(values.at(8).c_str());
  guest = std::atol(values.at(9).c_str());
  guestNice = std::atol(values.at(10).c_str());
  
  long idleTotal = idle + iowait;
  nonIdle = user + nice + system + irq + softIrq + steal;
  
  long prevTotal = prevIdleTotal + prevNonIdle;
  long total = idleTotal + nonIdle;

  long totalDiff = total - prevTotal;
  long idleDiff = idleTotal - prevIdleTotal;

  cpuPercentage = ((float)totalDiff - (float)idleDiff) / (float)totalDiff;

  prevIdle = idle;
  prevIowait = iowait;
  prevUser = user;
  prevNice = nice;
  prevSystem = system;
  prevIrq = irq;
  prevSoftIrq = softIrq;
  prevSteal = steal;

  return cpuPercentage;
}