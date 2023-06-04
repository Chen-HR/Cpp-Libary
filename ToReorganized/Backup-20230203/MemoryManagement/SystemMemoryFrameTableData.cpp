#include "Debug.hpp"
#ifndef SystemMemoryFrameTableData_hpp
  #include "SystemMemoryFrameTableData.hpp"
#endif
#ifndef SystemMemoryFrameTableData_cpp
  #define SystemMemoryFrameTableData_cpp
  SystemMemoryFrameTableData::SystemMemoryFrameTableData(std::size_t id, bool volid =false) 
    : ID(id), Volid(volid)
    {
      // debug_Flag(std::clog);
    }
#endif

