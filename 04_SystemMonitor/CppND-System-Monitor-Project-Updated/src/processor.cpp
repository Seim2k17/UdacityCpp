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
{
}

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {

// nice we have at least all values ^^
  std::vector<std::string> values = LinuxParser::CpuUtilization();


  for(auto i: values)
  {
    std::cout << i;
  }


  //long prevTotal = prevIdle + prevIowait;
  //long idleTotal = idle + iowait;

  float count(0.5);
  /*

PrevIdle = previdle + previowait
Idle = idle + iowait

PrevNonIdle = prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal
NonIdle = user + nice + system + irq + softirq + steal

PrevTotal = PrevIdle + PrevNonIdle
Total = Idle + NonIdle

# differentiate: actual value minus the previous one
totald = Total - PrevTotal
idled = Idle - PrevIdle

CPU_Percentage = (totald - idled)/totald





  for (int i = 1; i < 10; i++) {
    count += (1/i);
  }
  */
  return count;
}