#include "Debug.hpp"
#ifndef ProcessMemoryPagingTableData_hpp
  #include "ProcessMemoryPagingTableData.hpp"
#endif
#ifndef ProcessMemoryPagingTableData_cpp
  #define ProcessMemoryPagingTableData_cpp
  ProcessMemoryPagingTableData::ProcessMemoryPagingTableData(std::size_t id, bool volid =false, std::size_t systemMemoryFrame_ID =std::numeric_limits<std::size_t>::max()) 
    : ID(id), Volid(volid), SystemMemoryFrame_ID(systemMemoryFrame_ID)
    {debug_Flag(std::clog);}
#endif

