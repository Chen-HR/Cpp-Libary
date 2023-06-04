#include <iostream>
#ifndef ProcessMemoryPagingTableData_hpp
  #define ProcessMemoryPagingTableData_hpp
  class ProcessMemoryPagingTableData
    {
      private:
      protected:
      public:
        std::size_t ID;
        std::size_t SystemMemoryFrame_ID;
        bool Volid;
        ProcessMemoryPagingTableData(std::size_t, bool, std::size_t);
    };
#endif
#ifndef ProcessMemoryPagingTableData_cpp
  #include "ProcessMemoryPagingTableData.cpp"
#endif

