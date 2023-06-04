#include <list>
#include <string>
#include "SystemMemory.hpp"
#ifndef Process_hpp
  #define Process_hpp
  #include "ProcessMemory.hpp"
  class Process
    {
      private:
      protected:
      public:
        std::size_t ID;
        std::string Name;
        ProcessMemory ProcessMemory_;
        SystemMemory* SystemMemory_;
        Process(std::size_t, std::string, std::size_t, SystemMemory*, std::size_t);
        void deploy(std::size_t);
        void print(char*, std::size_t, std::ostream&);
        std::size_t physicalAddress(std::size_t, bool, bool, char*, std::size_t, std::ostream&);
        // void print(char*, std::size_t, std::ostream&);
    };
#endif
#ifndef Process_cpp
  #include "Process.cpp"
#endif

