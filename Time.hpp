#include <sstream> // std::stringstream
#include <iomanip>
#include <string>
#include <ctime>
#include <chrono>
#include <exception>
#include "Log.hpp"

#ifndef Time_hpp
  #define Time_hpp
  namespace Time
    {
      void Delay(double, clock_t);
      
      std::string Format_Current(const char*);

      class DateTime
        {
          private:
          protected:
          public:
            unsigned long long int time_milliseconds;
            short year_1900;
            short month_year;
            short day_year;
            short day_month;
            short day_week;
            short timezone_offset;
            short hour;
            short minute;
            short second;
            short milliseconds;
            DateTime();
            void set_current();
        };
      
      
    template <class ReturnType, class FuncType, class ArguType1> 
      ReturnType consumingTest(FuncType (*narrative)(ArguType1), ArguType1 Argu1);
    template <class ReturnType, class FuncType, class ArguType1, class ArguType2> 
      ReturnType consumingTest(FuncType (*narrative)(ArguType1,ArguType2), ArguType1 Argu1, ArguType2 Argu2);
    template <class ReturnType, class FuncType, class ArguType1, class ArguType2, class ArguType3> 
      ReturnType consumingTest(FuncType (*narrative)(ArguType1,ArguType2,ArguType3), ArguType1 Argu1, ArguType2 Argu2, ArguType3 Argu3);

      class ConsumingTest
        {
          private:
          protected:
          public:
            std::chrono::system_clock::time_point start_point;
            std::chrono::system_clock::time_point end_point;
            ConsumingTest();
            void start();
            void end();
            long long consum();
        };
    }
#endif //Time_hpp
#ifndef Time_cpp
  #include "Time.cpp"
#endif //Time_cpp
