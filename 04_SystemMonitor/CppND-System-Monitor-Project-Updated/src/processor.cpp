#include "processor.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  
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