#include <list>
#include "Process.hpp"
#include "Schedule.hpp"
#ifndef PROCESSSCHEDULESIMULATOR_HPP
  #define PROCESSSCHEDULESIMULATOR_HPP
  class ProcessScheduleSimulator
    {
      private:
      protected:
        inline Process* getArrivalProcess();
        inline Process* getRunningProcess();
        void ProcessList_toTable(char*, short);
      public:
        std::list<Process> ProcessList;
        Schedule schedule;
        unsigned long long int clock;
        ProcessScheduleSimulator(std::list<Process>, Schedule, unsigned long long int);
        ProcessScheduleSimulator setProcessScheduleSimulator(std::list<Process>, Schedule, unsigned long long int);
        void simulate(char*, short);
        inline double averageWaitingTime();
    };
  #ifndef PROCESSSCHEDULESIMULATOR_CPP
    #include "ProcessScheduleSimulator.cpp"
  #endif
#endif


