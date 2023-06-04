#include <list>
#include <map>
#ifndef SystemMemoryFrame_hpp
  #define SystemMemoryFrame_hpp
  #include "SystemMemoryFrameTableData.hpp"
  class SystemMemoryFrame
    {
      private:
      protected:
      public:
        std::size_t Size;
        std::size_t Number;
        std::list<SystemMemoryFrameTableData*> InvolidList;
        // std::map<std::size_t&, SystemMemoryFrameTableData&> FrameTable;
        // std::list<SystemMemoryFrameTableData*> FrameTable;
        SystemMemoryFrame(SystemMemoryFrame&);
        SystemMemoryFrame(std::size_t , std::size_t, bool);
    };
#endif
#ifndef SystemMemoryFrame_cpp
  #include "SystemMemoryFrame.cpp"
#endif

