#include <list>
#ifndef SystemMemory_hpp
  #define SystemMemory_hpp
  #include "SystemMemoryFrame.hpp"
  class SystemMemory
    {
      private:
      protected:
      public:
        std::size_t Size;
        SystemMemoryFrame Frame;
        SystemMemory(SystemMemory&);
        SystemMemory(std::size_t, std::size_t, bool);
    };
#endif
#ifndef SystemMemory_cpp
  #include "SystemMemory.cpp"
#endif

