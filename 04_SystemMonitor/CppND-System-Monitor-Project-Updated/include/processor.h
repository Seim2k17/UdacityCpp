#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  Processor();
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
  long prevUser, prevNice, prevSystem, prevIrq, prevSoftIrq, prevSteal, prevIowait;
  long user, nice, system, irq, softIrq, steal, iowait,guest, guestNice;
  long prevIdle, idle, prevNonIdle, nonIdle, prevTotal, total;
  float cpuPercentage;
};

#endif