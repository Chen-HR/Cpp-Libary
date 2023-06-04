#ifndef SCHEDULE_HPP
  #include "Schedule.hpp"
#endif
#ifndef SCHEDULE_CPP
  #define SCHEDULE_CPP
  Schedule::Schedule(std::string name_, bool preemptable_, unsigned long long int timeSlot_, bool (*compare_)(Process&, Process&))
    : name(name_), preemptable(preemptable_), timeSlot(timeSlot_), compare(compare_) 
    {}
#endif

