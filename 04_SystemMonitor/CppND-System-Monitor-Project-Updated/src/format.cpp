#include "format.h"

#include <chrono>
#include <iostream>
#include <string>

using std::string;

// DONE: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS

string Format::ElapsedTime(long seconds) {
  std::chrono::seconds dur(seconds);

  // https://en.cppreference.com/w/cpp/chrono/duration
  // integer scale conversion with precision loss: requires a cast
  auto hours = std::chrono::duration_cast<std::chrono::hours>(dur).count();
  auto minutes = std::chrono::duration_cast<std::chrono::minutes>(dur).count();
  auto secs = std::chrono::duration_cast<std::chrono::seconds>(dur).count();

  minutes %= 60;
  secs %= 60;

  std::string timeFormat = string();
  hours < 10 ? timeFormat += ("0") + std::to_string(hours)
             : timeFormat += std::to_string(hours);
  timeFormat += ":";
  minutes < 10 ? timeFormat += ("0") + std::to_string(minutes)
               : timeFormat += std::to_string(minutes);
  timeFormat += ":";
  secs < 10 ? timeFormat += ("0") + std::to_string(secs)
            : timeFormat += std::to_string(secs);

  return timeFormat;
}