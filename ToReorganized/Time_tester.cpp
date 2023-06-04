#include <iostream>
#include <exception>
#include "Time.hpp"

int main ()
  {
    std::cout << Time::Format_Current("%Y/%m/%d %H:%M:%S") << std::endl;
    Time::ConsumingTest RunTimeTester;
    Time::Delay(1000);
    RunTimeTester.end();
    std::cout << Time::Format_Current("%Y/%m/%d %H:%M:%S") << ": " << RunTimeTester.consum() << std::endl;
    try
      {
        Time::DateTime current;
        // Log::log("current.timezone_offset", current.timezone_offset);
      }
    catch(const std::exception& exception)
      {
        std::cerr << exception.what() << std::endl;
      }
  }