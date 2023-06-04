#include <iostream>
#include "Time.hpp"
#include "Log.hpp"

int main() 
  {
    Log_log_filePosition("");
    Log::log("main", "start forLoop");
    for (size_t i = 0; i < 10; i++)
      { 
        Log::log("main>forLoop", "run forLoop");
        Time::Delay(50);
      }
    Log_log_filePosition("");
    Log::log("main", "end forLoop");
    
    Log::log_data_number<unsigned long long, 16, 0, '0', 16>("", "", 0x7094B05E800C69B1ull);
  }
