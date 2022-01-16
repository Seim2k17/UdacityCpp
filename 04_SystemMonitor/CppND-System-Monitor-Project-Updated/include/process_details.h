#ifndef PROCESS_DETAILS_H
#define PROCESS_DETAILS_H

#include "process.h"
#include <string>
/*
Basic class for Process Details representation
It contains relevant attributes as shown below
*/
class ProcessDetails {
 public:

  ProcessDetails();
  ProcessDetails(int pid);                              
  void User(std::string user);                    
  void UserId(std::string userId);
  void Command(std::string command);              
  void CpuUtilization(std::string cpu_util);            
  void Ram(std::string ram_util);                 
  void UpTime(std::string uptime);

  int Pid();
  std::string User();                    
  std::string UserId();
  std::string Command();              
  std::string CpuUtilization();            
  std::string Ram();                 
  std::string UpTime();                   
  //bool operator<(Process const& a) const;  // TODO: See src/process.cpp
 
 private:
    int m_pid;
    std::string m_user;
    std::string m_userId;
    std::string m_command;
    std::string m_cpu_utilization;
    std::string m_ram_utilization;
    std::string m_uptime;
};

#endif
