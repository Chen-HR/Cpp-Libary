// #include "Log.hpp"

#ifndef Time_hpp
  #include "Time.hpp"
#endif //Time_hpp
#ifndef Time_cpp
  #define Time_cpp
  void Time::Delay(double delay, clock_t ms=1)
    { double StartTime = (double)(std::clock());
      while (((((double)(std::clock())))-StartTime)<delay*ms); }
  
  std::string Time::Format_Current(const char* Format) 
    { // todo: support milliseconds
      std::chrono::system_clock::time_point current = std::chrono::system_clock::now();
      // long long current_ms = std::chrono::duration_cast<std::chrono::milliseconds>(current.time_since_epoch()).count()%1000;
      std::time_t current_datetime = std::chrono::system_clock::to_time_t(current);
      std::tm current_datetime_struct = *std::localtime(&current_datetime);
      // Log::log("duration_cast", std::chrono::duration_cast<std::chrono::milliseconds>(current.time_since_epoch()).count() );
      // Log::log("system_clock ", std::chrono::system_clock::to_time_t(current) );
      // Log::log("std::tm.tm_year ", current_datetime_struct.tm_year );
      // Log::log("std::tm.tm_mon  ", current_datetime_struct.tm_mon  );
      // Log::log("std::tm.tm_mday ", current_datetime_struct.tm_mday );
      // Log::log("std::tm.tm_yday ", current_datetime_struct.tm_yday );
      // Log::log("std::tm.tm_wday ", current_datetime_struct.tm_wday );
      // Log::log("std::tm.tm_hour ", current_datetime_struct.tm_hour );
      // Log::log("std::tm.tm_min  ", current_datetime_struct.tm_min  );
      // Log::log("std::tm.tm_sec  ", current_datetime_struct.tm_sec  );
      // Log::log("std::tm.tm_isdst", current_datetime_struct.tm_isdst);
      std::stringstream result_stringstream;
      // result_stringstream << std::put_time(&current_datetime_struct, Format) << "." << std::setw(3) << std::setfill('0') << current_ms;
      result_stringstream << std::put_time(&current_datetime_struct, Format);
      return result_stringstream.str();
    }
  Time::DateTime::DateTime()
    { this->set_current(); }
  void Time::DateTime::set_current()
    {
      std::chrono::system_clock::time_point current = std::chrono::system_clock::now();
      long long time_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
      std::time_t time_seconds = time_milliseconds/1000;
      this->time_milliseconds=time_milliseconds;
      this->milliseconds=time_milliseconds%1000;
      std::tm time_local = *std::localtime(&time_seconds);
      std::tm time_utc   = *std::gmtime(&time_seconds);
      this->year_1900  = time_local.tm_year;
      this->month_year = time_local.tm_mon ;
      this->day_year   = time_local.tm_yday;
      this->day_month  = time_local.tm_mday;
      this->day_week   = time_local.tm_wday;
      this->hour       = time_local.tm_hour;
      this->minute     = time_local.tm_min ;
      this->second     = time_local.tm_sec ;
      this->timezone_offset = time_local.tm_hour-time_utc.tm_hour;
      if (this->timezone_offset<-12) this->timezone_offset=24-this->timezone_offset;
      if (this->timezone_offset> 12) this->timezone_offset=this->timezone_offset-24;
      // Log::log("time_milliseconds", this->time_milliseconds);
      // Log::log("year_1900 ", this->year_1900 );
      // Log::log("month_year", this->month_year);
      // Log::log("day_year  ", this->day_year  );
      // Log::log("day_month ", this->day_month );
      // Log::log("day_week  ", this->day_week  );
      // Log::log("hour      ", this->hour      );
      // Log::log("minute    ", this->minute    );
      // Log::log("second    ", this->second    );
      // Log::log("milliseconds", this->milliseconds);
      // Log::log("timezone_offset", this->timezone_offset);
    }

    
    template <class ReturnType, class FuncType, class ArguType1> ReturnType consumingTest(FuncType (*narrative)(ArguType1),ArguType1 Argu1)
      {
        double startTime = double(clock());
        ((*narrative)(Argu1));
        double endTime   = double(clock());
        return (endTime-startTime);
      }
    template <class ReturnType, class FuncType, class ArguType1, class ArguType2> ReturnType consumingTest(FuncType (*narrative)(ArguType1,ArguType2),ArguType1 Argu1,ArguType2 Argu2)
      {
        double startTime = double(clock());
        ((*narrative)(Argu1,Argu2));
        double endTime   = double(clock());
        return (endTime-startTime);
      }
    template <class ReturnType, class FuncType, class ArguType1, class ArguType2, class ArguType3> ReturnType consumingTest(FuncType (*narrative)(ArguType1,ArguType2,ArguType3),ArguType1 Argu1,ArguType2 Argu2,ArguType3 Argu3)
      {
        double startTime = double(clock());
        ((*narrative)(Argu1,Argu2,Argu3));
        double endTime   = double(clock());
        return (endTime-startTime);
      }
    
    Time::ConsumingTest::ConsumingTest()
      :start_point(std::chrono::system_clock::now()), end_point(start_point) {}
    void Time::ConsumingTest::start()
      {
        this->start_point = this->end_point = std::chrono::system_clock::now();
      }
    void Time::ConsumingTest::end()
      {
        this->end_point = std::chrono::system_clock::now();
      }
    long long Time::ConsumingTest::consum()
      {
        return std::chrono::duration_cast<std::chrono::milliseconds>(this->end_point-this->start_point).count();
      }
#endif //Time_cpp
