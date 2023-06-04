#include <iostream>
#ifndef SystemMemoryFrameTableData_hpp
  #define SystemMemoryFrameTableData_hpp
  class SystemMemoryFrameTableData
    {
      private:
      protected:
      public:
        const std::size_t ID;
        bool Volid;
        SystemMemoryFrameTableData(std::size_t, bool);
    } ;
#endif
#ifndef SystemMemoryFrameTableData_cpp
  #include "SystemMemoryFrameTableData.cpp"
#endif

