#include <list>
#include <iostream>
#include "SystemMemoryFrame.hpp"
#ifndef ProcessMemoryPaging_hpp
  #define ProcessMemoryPaging_hpp
  #include "ProcessMemoryPagingTableData.hpp"
  class ProcessMemoryPaging
    {
      private:
      protected:
      public:
        std::size_t Number;
        std::list<ProcessMemoryPagingTableData*> PagingTable;
        SystemMemoryFrame& Frame;
        ProcessMemoryPaging(ProcessMemoryPaging&);
        ProcessMemoryPaging(std::size_t, SystemMemoryFrame&);
        void deploy(std::size_t);
        void print(char*, std::size_t, std::ostream&);
    };
#endif
#ifndef ProcessMemoryPaging_cpp
  #include "ProcessMemoryPaging.cpp"
#endif

