#include "process_details.h"

ProcessDetails::ProcessDetails()
{}


ProcessDetails::ProcessDetails(int pid)
{
    m_pid = pid;
}

void ProcessDetails::User(std::string user)
{
    m_user = user;
}

void ProcessDetails::UserId(std::string userId)
{
    m_userId = userId;
}
  
void ProcessDetails::Command(std::string command)
{
    m_command = command;
}

void ProcessDetails::CpuUtilization(std::string cpu_util)
{
    m_cpu_utilization = cpu_util;
}

void ProcessDetails::Ram(std::string ram_util)
{
    m_ram_utilization=ram_util;
}

void ProcessDetails::UpTime(std::string uptime)
{
    m_uptime = uptime;
}