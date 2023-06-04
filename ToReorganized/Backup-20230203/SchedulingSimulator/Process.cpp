#ifndef PROCESS_HPP
  #include "Process.hpp"
#endif
#ifndef PROCESS_CPP
  #define PROCESS_CPP
  Process::Process (std::string name_, unsigned long long int arrival_, unsigned long long int priority_, unsigned long long int requirement_, 
                    unsigned long long int ready_=0, unsigned long long int continuous_=0, ProcessState state_=ProcessState::New)
    : name(name_), firstArrive(arrival_), arrival(arrival_), priority(priority_), requirement(requirement_), ready(ready_), continuous(continuous_), state(state_)
    {}
  inline const char* Process::getStateString()
    {
      return Process::ProcessStateName[(unsigned long long int)(state)];
    }
  Process* Process::changState(Process::ProcessState target, unsigned long long int clock)
    {
      Process::ProcessState initial=this->state;
      this->state=target;
      if (initial==Process::ProcessState::Running && target!=Process::ProcessState::Running)
        this->continuous=0;
      if (initial==Process::ProcessState::Running && target!=Process::ProcessState::Running)
        this->arrival=clock;
      return this;
    }
  Process* Process::step(unsigned long long int clock)
    {
      switch (this->state)
        {
          case Process::ProcessState::Ready:
              this->ready++;
            break;
          case Process::ProcessState::Running:
              this->continuous++;
              this->requirement--;
            break;
          default:
            break;
        };
      return this;
    }
#endif

