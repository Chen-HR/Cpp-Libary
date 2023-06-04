#include <list>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Container.hpp"
#include "Process.hpp"
#include "Schedule.hpp"
#ifndef PROCESSSCHEDULESIMULATOR_HPP
  #include "ProcessScheduleSimulator.hpp"
#endif
#ifndef PROCESSSCHEDULESIMULATOR_CPP
  #define PROCESSSCHEDULESIMULATOR_CPP
  ProcessScheduleSimulator::ProcessScheduleSimulator(std::list<Process> ProcessList_, Schedule schedule_, unsigned long long int clock_=0)
    : ProcessList(ProcessList_), schedule(schedule_), clock(clock_) {}
  ProcessScheduleSimulator ProcessScheduleSimulator::setProcessScheduleSimulator(std::list<Process> ProcessList_, Schedule schedule_, unsigned long long int clock_=0)
    {
      ProcessList = ProcessList_;
      schedule = schedule_;
      clock = clock_;
      return *this;
    }
  inline Process* ProcessScheduleSimulator::getArrivalProcess()
    {
      return Container::select_pointer<std::list<Process>, Process, unsigned long long int>
              (this->ProcessList, this->clock, [](Process& process, unsigned long long int& clock) -> bool {return (process.arrival==clock);});
    }
  inline Process* ProcessScheduleSimulator::getRunningProcess()
    {
      return Container::select_pointer<std::list<Process>, Process, unsigned long long int>
              (this->ProcessList, this->clock, [](Process& process, unsigned long long int& clock) -> bool {return (process.state==Process::ProcessState::Running);});
    }
  void ProcessScheduleSimulator::ProcessList_toTable(char* lineStart=(char*)(""), short fieldMask=125)
    {
      unsigned long long int fieldWidth_name        = std::max<unsigned long long int>( 4, Container::max<unsigned long long int, std::list<Process>, Process>
                            (this->ProcessList, [](Process& process)-> unsigned long long int {return process.name.length();}));
      unsigned long long int fieldWidth_arrival     = std::max<unsigned long long int>( 7, Container::max<unsigned long long int, std::list<Process>, Process>
                            (this->ProcessList, [](Process& process)-> unsigned long long int {return std::ceil(process.arrival    ?std::log10(process.arrival    ):0);}));
      unsigned long long int fieldWidth_priority    = std::max<unsigned long long int>( 8, Container::max<unsigned long long int, std::list<Process>, Process>
                            (this->ProcessList, [](Process& process)-> unsigned long long int {return std::ceil(process.priority   ?std::log10(process.priority   ):0);}));
      unsigned long long int fieldWidth_requirement = std::max<unsigned long long int>(11, Container::max<unsigned long long int, std::list<Process>, Process>
                            (this->ProcessList, [](Process& process)-> unsigned long long int {return std::ceil(process.requirement?std::log10(process.requirement):0);}));
      unsigned long long int fieldWidth_ready       = std::max<unsigned long long int>( 5, Container::max<unsigned long long int, std::list<Process>, Process>
                            (this->ProcessList, [](Process& process)-> unsigned long long int {return std::ceil(process.ready      ?std::log10(process.ready      ):0);}));
      unsigned long long int fieldWidth_continuous  = std::max<unsigned long long int>(10, Container::max<unsigned long long int, std::list<Process>, Process>
                            (this->ProcessList, [](Process& process)-> unsigned long long int {return std::ceil(process.continuous ?std::log10(process.continuous ):0);}));
      unsigned long long int fieldWidth_state       = 10;
      std::cout<<lineStart<<" + ";
      if (fieldMask &  64) { for (unsigned long long int index=0; index<fieldWidth_name       ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &  32) { for (unsigned long long int index=0; index<fieldWidth_arrival    ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &  16) { for (unsigned long long int index=0; index<fieldWidth_priority   ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &   8) { for (unsigned long long int index=0; index<fieldWidth_requirement; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &   4) { for (unsigned long long int index=0; index<fieldWidth_ready      ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &   2) { for (unsigned long long int index=0; index<fieldWidth_continuous ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &   1) { for (unsigned long long int index=0; index<fieldWidth_state      ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      std::cout<<std::endl;
      std::cout<<lineStart<<" | ";
      if (fieldMask &  64) std::cout<<std::setw(fieldWidth_name       )<<"name"       <<" | ";
      if (fieldMask &  32) std::cout<<std::setw(fieldWidth_arrival    )<<"arrival"    <<" | ";
      if (fieldMask &  16) std::cout<<std::setw(fieldWidth_priority   )<<"priority"   <<" | ";
      if (fieldMask &   8) std::cout<<std::setw(fieldWidth_requirement)<<"requirement"<<" | ";
      if (fieldMask &   4) std::cout<<std::setw(fieldWidth_ready      )<<"ready"      <<" | ";
      if (fieldMask &   2) std::cout<<std::setw(fieldWidth_continuous )<<"continuous" <<" | ";
      if (fieldMask &   1) std::cout<<std::setw(fieldWidth_state      )<<"state"      <<" | ";
      std::cout<<std::endl;
      std::cout<<lineStart<<" + ";
      if (fieldMask &  64) { for (unsigned long long int index=0; index<fieldWidth_name       ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &  32) { for (unsigned long long int index=0; index<fieldWidth_arrival    ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &  16) { for (unsigned long long int index=0; index<fieldWidth_priority   ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &   8) { for (unsigned long long int index=0; index<fieldWidth_requirement; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &   4) { for (unsigned long long int index=0; index<fieldWidth_ready      ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &   2) { for (unsigned long long int index=0; index<fieldWidth_continuous ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &   1) { for (unsigned long long int index=0; index<fieldWidth_state      ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      std::cout<<std::endl;
      for (Process& process: ProcessList)
        {
          std::cout<<lineStart<<" | ";
          if (fieldMask &  64) std::cout<<std::setw(fieldWidth_name       )<<process.name       <<" | ";
          if (fieldMask &  32) std::cout<<std::setw(fieldWidth_arrival    )<<process.arrival    <<" | ";
          if (fieldMask &  16) std::cout<<std::setw(fieldWidth_priority   )<<process.priority   <<" | ";
          if (fieldMask &   8) std::cout<<std::setw(fieldWidth_requirement)<<process.requirement<<" | ";
          if (fieldMask &   4) std::cout<<std::setw(fieldWidth_ready      )<<process.ready      <<" | ";
          if (fieldMask &   2) std::cout<<std::setw(fieldWidth_continuous )<<process.continuous <<" | ";
          if (fieldMask &   1) std::cout<<std::setw(fieldWidth_state      )<<Process::ProcessStateName[process.state]<<" | ";
          std::cout<<std::endl;
        }
      std::cout<<lineStart<<" + ";
      if (fieldMask &  64) { for (unsigned long long int index=0; index<fieldWidth_name       ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &  32) { for (unsigned long long int index=0; index<fieldWidth_arrival    ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &  16) { for (unsigned long long int index=0; index<fieldWidth_priority   ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &   8) { for (unsigned long long int index=0; index<fieldWidth_requirement; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &   4) { for (unsigned long long int index=0; index<fieldWidth_ready      ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &   2) { for (unsigned long long int index=0; index<fieldWidth_continuous ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      if (fieldMask &   1) { for (unsigned long long int index=0; index<fieldWidth_state      ; index++) { std::cout<<"-"; } std::cout<<" + "; }
      std::cout<<std::endl;
    }
  void ProcessScheduleSimulator::simulate(char* lineStart=(char*)(""), short TimingDiagramLevel=1)
    {
      if (TimingDiagramLevel)
        {
          std::cout<<lineStart<<"Launch Simulator: "<<std::endl;
          std::cout<<lineStart<<"  Schedule Information: "<<std::endl;
          std::cout<<lineStart<<"    Name       : "<<schedule.name<<std::endl;
          std::cout<<lineStart<<"    Preemptable: "<<((schedule.preemptable)?"True":"False")<<std::endl;
          std::cout<<lineStart<<"    TimeSlot   : "<<((schedule.timeSlot)?std::to_string(schedule.timeSlot):"Disabled")<<std::endl;
          std::cout<<lineStart<<"  Process Initial Information: "<<std::endl;
          this->ProcessList_toTable((char*)("    "));
        }
      if (TimingDiagramLevel==2 || TimingDiagramLevel==3) std::cout<<lineStart<<"  Simulator Execution Information: "<<std::endl;
      Process* ArrivalProcess; Process* RunningProcess;
      for (; Container::sum<unsigned long long int, std::list<Process>, Process>(this->ProcessList, [](Process& process) -> unsigned long long int {return process.requirement;}); this->clock++)
        {
          bool stateChanged=false;
          if (TimingDiagramLevel==3) std::cout<<lineStart<<"    clock: 0x"<<std::setw(8)<<std::setfill('0')<<std::setbase(16)<<clock<<": [ ";

          ArrivalProcess = this->getArrivalProcess();
          RunningProcess = this->getRunningProcess();
          if (ArrivalProcess && ArrivalProcess->state==Process::ProcessState::New) 
            {
              if (TimingDiagramLevel==2 && !stateChanged) std::cout<<lineStart<<"    clock: 0x"<<std::setw(8)<<std::setfill('0')<<std::setbase(16)<<clock<<": [ ";
              ArrivalProcess->changState(Process::ProcessState::Ready, clock);
              if (TimingDiagramLevel==2 || TimingDiagramLevel==3) { std::cout<<"Arrival:\""<<ArrivalProcess->name<<"\"."<<Process::ProcessStateName[ArrivalProcess->state]; stateChanged=true; }
            }

          ArrivalProcess = this->getArrivalProcess();
          RunningProcess = this->getRunningProcess();
          if (RunningProcess && ArrivalProcess && schedule.preemptable && schedule.compare(*ArrivalProcess, *RunningProcess))
            {
              if (TimingDiagramLevel==2 && !stateChanged) std::cout<<lineStart<<"    clock: 0x"<<std::setw(8)<<std::setfill('0')<<std::setbase(16)<<clock<<": [ ";
              RunningProcess->changState(Process::ProcessState::Ready, clock);
              if (stateChanged) std::cout<<", ";
              if (TimingDiagramLevel==2 || TimingDiagramLevel==3) { std::cout<<"Preempted:\""<<RunningProcess->name<<"\"."<<Process::ProcessStateName[RunningProcess->state]; stateChanged=true; }
              RunningProcess = ArrivalProcess->changState(Process::ProcessState::Running, clock);
              if (TimingDiagramLevel==2 || TimingDiagramLevel==3) { std::cout<<", Preempting:\""<<ArrivalProcess->name<<"\"."<<Process::ProcessStateName[ArrivalProcess->state]; stateChanged=true; }
            }
          ArrivalProcess = this->getArrivalProcess();
          RunningProcess = this->getRunningProcess();
          if (RunningProcess && RunningProcess->requirement<=0)
            {
              if (TimingDiagramLevel==2 && !stateChanged) std::cout<<lineStart<<"    clock: 0x"<<std::setw(8)<<std::setfill('0')<<std::setbase(16)<<clock<<": [ ";
              RunningProcess->changState(Process::ProcessState::Terminated, clock);
              if (stateChanged) std::cout<<", ";
              if (TimingDiagramLevel==2 || TimingDiagramLevel==3) { std::cout<<"NoRequire:\""<<RunningProcess->name<<"\"."<<Process::ProcessStateName[RunningProcess->state]; stateChanged=true; }
            }
          ArrivalProcess = this->getArrivalProcess();
          RunningProcess = this->getRunningProcess();
          if (RunningProcess && schedule.timeSlot && (RunningProcess->continuous >= schedule.timeSlot))
            {
              if (TimingDiagramLevel==2 && !stateChanged) std::cout<<lineStart<<"    clock: 0x"<<std::setw(8)<<std::setfill('0')<<std::setbase(16)<<clock<<": [ ";
              RunningProcess->changState(Process::ProcessState::Ready, clock);
              if (stateChanged) std::cout<<", ";
              if (TimingDiagramLevel==2 || TimingDiagramLevel==3) { std::cout<<"FullTimeSlot:\""<<RunningProcess->name<<"\"."<<Process::ProcessStateName[RunningProcess->state]; stateChanged=true; }
            }
          ProcessList.sort(schedule.compare);
          ArrivalProcess = this->getArrivalProcess();
          RunningProcess = this->getRunningProcess();
          if (!RunningProcess)
            {
              for (Process& process: this->ProcessList) if (process.state==Process::ProcessState::Ready)
                {
                  if (TimingDiagramLevel==2 && !stateChanged) std::cout<<lineStart<<"    clock: 0x"<<std::setw(8)<<std::setfill('0')<<std::setbase(16)<<clock<<": [ ";
                  RunningProcess = process.changState(Process::ProcessState::Running, clock);
                  if (stateChanged) std::cout<<", ";
                  if (TimingDiagramLevel==2 || TimingDiagramLevel==3) { std::cout<<"NoRunning:\""<<RunningProcess->name<<"\"."<<Process::ProcessStateName[RunningProcess->state]; stateChanged=true; }
                  break;
                }
            }
          Container::forEach<std::list<Process>, Process, unsigned long long int>(this->ProcessList, clock, [](Process& process, unsigned long long int& clock){ process.step(clock);});
          if (TimingDiagramLevel==3 || stateChanged) std::cout<<" ]"<<std::setfill(' ')<<std::setbase(10)<<std::endl;
          if (TimingDiagramLevel==3) this->ProcessList_toTable((char*)("        "), 127);
        }
      RunningProcess = this->getRunningProcess();
      if (RunningProcess && RunningProcess->requirement<=0)
        {
          if (TimingDiagramLevel==2 || TimingDiagramLevel==3)  std::cout<<lineStart<<"    clock: 0x"<<std::setw(8)<<std::setfill('0')<<std::setbase(16)<<clock<<": [ ";
          RunningProcess->changState(Process::ProcessState::Terminated, clock);
          if (TimingDiagramLevel==2 || TimingDiagramLevel==3) std::cout<<"NoRequire:\""<<RunningProcess->name<<"\"."<<Process::ProcessStateName[RunningProcess->state]<<" ]"<<std::setfill(' ')<<std::setbase(10)<<std::endl;
        }
      
      if (TimingDiagramLevel)
        {
          std::cout<<lineStart<<"  Process Final Information: "<<std::endl;
          this->ProcessList_toTable((char*)("    "));
        }
    }
  inline double ProcessScheduleSimulator::averageWaitingTime()
    {
      return (double)(Container::sum<unsigned long long int, std::list<Process>, Process>(this->ProcessList, [](Process& process) -> unsigned long long int {return process.ready;}))/this->ProcessList.size();
    }
#endif
