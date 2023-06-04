#ifndef PROCESS_HPP
  #define PROCESS_HPP
  #include <string>
  class Process
    {
      private:
      protected:
      public:
        enum ProcessState { New = 0, Ready = 1, Running = 2, Waiting = 3, Terminated = 4 };
        #if __cplusplus < 201703
          static const char* ProcessStateName[];
        #else 
          static constexpr const char* ProcessStateName[] = 
            { "New", "Ready", "Running", "Waiting", "Terminated" };
        #endif
        std::string name;
        unsigned long long int firstArrive;
        unsigned long long int arrival    ;
        unsigned long long int priority   ;
        unsigned long long int requirement;
        unsigned long long int ready      ;
        unsigned long long int continuous ;
        ProcessState state;
        Process(std::string, unsigned long long int, unsigned long long int, unsigned long long int, 
                unsigned long long int, unsigned long long int, ProcessState);
        inline const char* getStateString();
        Process* changState(ProcessState, unsigned long long int);
        Process* step(unsigned long long int);
    };
  #if __cplusplus < 201703
    const char* Process::ProcessStateName[] = { "New", "Ready", "Running", "Waiting", "Terminated" };
  #endif
  #ifndef PROCESS_CPP
    #include "Process.cpp"
  #endif
#endif

