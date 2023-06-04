#ifndef PROCESS_HPP
  #include "Process.hpp"
#endif
#ifndef SCHEDULE_HPP
  #define SCHEDULE_HPP
  class Schedule
    {
      private:
      protected:
      public:
        std::string name;
        bool preemptable;
        unsigned long long int timeSlot;
        bool (*compare)(Process&, Process&);
        Schedule(std::string name_, bool preemptable_, unsigned long long int timeSlot_, bool (*compare_)(Process&, Process&));
    };
  #ifndef SCHEDULE_CPP
    #include "Schedule.cpp"
  #endif
#endif

