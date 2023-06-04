#include <list>
#include <string>
#ifndef System_hpp
  #define System_hpp
  #include "SystemMemory.hpp"
  #include "Process.hpp"
  class System
    {
      private:
      protected:
      public:
        SystemMemory Memory;
        std::size_t NumberDispatchRecord;
        std::list<Process> Processes;
        System(SystemMemory&);
        void addProcess(std::string, std::size_t, std::size_t );
        // std::size_t physicalAddress(std::size_t, std::size_t, bool, bool, char*, std::size_t, std::ostream&);
        std::size_t physicalAddress(std::string, std::size_t, bool, bool, char*, std::size_t, std::ostream&);
    };
#endif
#ifndef System_cpp
  #include "System.cpp"
#endif