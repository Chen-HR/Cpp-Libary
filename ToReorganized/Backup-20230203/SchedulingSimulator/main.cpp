#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <list>
#include "ProcessScheduleSimulator.hpp"
template <class Type> inline Type stdinReader()
  {
    Type buffer;
    std::cin>>buffer;
    return buffer;
  }
int main(int argc, char** argv)
  {
    std::cout<<"Process Number: "; unsigned long long int ProcessNumber=stdinReader<unsigned long long int>();
    std::cout<<"Process Information: "<<std::endl; std::list<Process> ProcessInformation;
    for (unsigned long long int index=0; index<ProcessNumber; index++)
      {
        std::cout<<"  Process "<<index<<" of "<<ProcessNumber<<": "<<std::endl;
        std::cout<<"    name       : "; std::string            name        = stdinReader<std::string           >();
        std::cout<<"    arrival    : "; unsigned long long int arrival     = stdinReader<unsigned long long int>();
        std::cout<<"    priority   : "; unsigned long long int priority    = stdinReader<unsigned long long int>();
        std::cout<<"    requirement: "; unsigned long long int requirement = stdinReader<unsigned long long int>();
        ProcessInformation.push_back(Process(name, arrival, priority, requirement));
      }
    Schedule FCFS ("FCFS"               , false , 0, [](Process& Process1, Process& Process2) -> bool 
                   {return (Process1.arrival    <=Process2.arrival    );});
    Schedule NPSJF("Non-Preemptive SJF" , false , 0, [](Process& Process1, Process& Process2) -> bool 
                   {return (Process1.requirement<=Process2.requirement);});
    Schedule PSJF ("Preemptive SJF"     , true  , 0, [](Process& Process1, Process& Process2) -> bool 
                   {return (Process1.requirement<=Process2.requirement);});
    Schedule PP   ("Preemptive Priority", true  , 0, [](Process& Process1, Process& Process2) -> bool 
                   {return (Process1.priority   <=Process2.priority   );});
    Schedule RR   ("Round-Robin(FCFS)"  , false , 2, [](Process& Process1, Process& Process2) -> bool 
                   {return (Process1.arrival    ==Process2.arrival    )?(Process1.firstArrive<=Process2.firstArrive):(Process1.arrival<Process2.arrival);});
    ProcessScheduleSimulator FCFS_Simulator (ProcessInformation, FCFS , 0);
    ProcessScheduleSimulator NPSJF_Simulator(ProcessInformation, NPSJF, 0);
    ProcessScheduleSimulator PSJF_Simulator (ProcessInformation, PSJF , 0);
    ProcessScheduleSimulator PP_Simulator   (ProcessInformation, PP   , 0);
    ProcessScheduleSimulator RR_Simulator   (ProcessInformation, RR   , 0);
    std::cout<<"==============================================================================================================="<<std::endl;
    std::cout<<"Start Simulate "<<FCFS_Simulator .schedule.name<<": "<<std::endl; FCFS_Simulator .simulate((char*)("  "),2);
    std::cout<<"The averageWaitingTime of "<<std::setw(20)<<FCFS_Simulator .schedule.name<<" is "
              <<std::setw(10)<<std::fixed<<std::setprecision(4)<<FCFS_Simulator .averageWaitingTime()<<" timeUnit(clock)."<<std::endl;
    std::cout<<"==============================================================================================================="<<std::endl;
    std::cout<<"Start Simulate "<<NPSJF_Simulator.schedule.name<<": "<<std::endl; NPSJF_Simulator.simulate((char*)("  "),2);
    std::cout<<"The averageWaitingTime of "<<std::setw(20)<<NPSJF_Simulator.schedule.name<<" is "
              <<std::setw(10)<<std::fixed<<std::setprecision(4)<<NPSJF_Simulator.averageWaitingTime()<<" timeUnit(clock)."<<std::endl;
    std::cout<<"==============================================================================================================="<<std::endl;
    std::cout<<"Start Simulate "<<PSJF_Simulator .schedule.name<<": "<<std::endl; PSJF_Simulator .simulate((char*)("  "),2);
    std::cout<<"The averageWaitingTime of "<<std::setw(20)<<PSJF_Simulator .schedule.name<<" is "
              <<std::setw(10)<<std::fixed<<std::setprecision(4)<<PSJF_Simulator .averageWaitingTime()<<" timeUnit(clock)."<<std::endl;
    std::cout<<"==============================================================================================================="<<std::endl;
    std::cout<<"Start Simulate "<<PP_Simulator   .schedule.name<<": "<<std::endl; PP_Simulator   .simulate((char*)("  "),2);
    std::cout<<"The averageWaitingTime of "<<std::setw(20)<<PP_Simulator   .schedule.name<<" is "
              <<std::setw(10)<<std::fixed<<std::setprecision(4)<<PP_Simulator   .averageWaitingTime()<<" timeUnit(clock)."<<std::endl;
    std::cout<<"==============================================================================================================="<<std::endl;
    std::cout<<"Start Simulate "<<RR_Simulator   .schedule.name<<": "<<std::endl; RR_Simulator   .simulate((char*)("  "),2);
    std::cout<<"The averageWaitingTime of "<<std::setw(20)<<RR_Simulator   .schedule.name<<" is "
              <<std::setw(10)<<std::fixed<<std::setprecision(4)<<RR_Simulator   .averageWaitingTime()<<" timeUnit(clock)."<<std::endl;
    std::cout<<"==============================================================================================================="<<std::endl;
    std::cout<<"The averageWaitingTime of "<<std::setw(20)<<FCFS_Simulator .schedule.name<<" is "
              <<std::setw(10)<<std::fixed<<std::setprecision(4)<<FCFS_Simulator .averageWaitingTime()<<" timeUnit(clock)."<<std::endl;
    std::cout<<"The averageWaitingTime of "<<std::setw(20)<<NPSJF_Simulator.schedule.name<<" is "
              <<std::setw(10)<<std::fixed<<std::setprecision(4)<<NPSJF_Simulator.averageWaitingTime()<<" timeUnit(clock)."<<std::endl;
    std::cout<<"The averageWaitingTime of "<<std::setw(20)<<PSJF_Simulator .schedule.name<<" is "
              <<std::setw(10)<<std::fixed<<std::setprecision(4)<<PSJF_Simulator .averageWaitingTime()<<" timeUnit(clock)."<<std::endl;
    std::cout<<"The averageWaitingTime of "<<std::setw(20)<<PP_Simulator   .schedule.name<<" is "
              <<std::setw(10)<<std::fixed<<std::setprecision(4)<<PP_Simulator   .averageWaitingTime()<<" timeUnit(clock)."<<std::endl;
    std::cout<<"The averageWaitingTime of "<<std::setw(20)<<RR_Simulator   .schedule.name<<" is "
              <<std::setw(10)<<std::fixed<<std::setprecision(4)<<RR_Simulator   .averageWaitingTime()<<" timeUnit(clock)."<<std::endl;
    return 0;
  }
