#include "SystemMemory.hpp"
#include "SystemMemoryFrame.hpp"
#ifndef ProcessMemory_hpp
  #define ProcessMemory_hpp
  #include "ProcessMemoryPaging.hpp"
  class ProcessMemory
    {
      private:
      protected:
      public:
        std::size_t Size;
        ProcessMemoryPaging Paging;
        SystemMemoryFrame& Frame;
        // SystemMemory* SystemMemory_;
        ProcessMemory(ProcessMemory&);
        ProcessMemory(std::size_t, SystemMemoryFrame&);
        void deploy(std::size_t);
        void print(char*, std::size_t, std::ostream&);
        std::size_t physicalAddress(std::size_t, bool, bool, char*, std::size_t, std::ostream&);
    };
#endif
#ifndef ProcessMemory_cpp
  #include "ProcessMemory.cpp"
#endif

