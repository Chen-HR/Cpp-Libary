#include "Debug.hpp"
#include <random>
#include <chrono>
#include <algorithm>
#ifndef SystemMemory_hpp
  #include "SystemMemory.hpp"
#endif
#ifndef SystemMemory_cpp
  #define SystemMemory_cpp
  SystemMemory::SystemMemory(SystemMemory& systemMemory) 
    : Size(systemMemory.Size), Frame(systemMemory.Frame)
    {
      debug_Flag(std::clog);
    }
  SystemMemory::SystemMemory(std::size_t size, std::size_t frameSize, bool RandomFrameInvolidList=true) 
    : Size(size), Frame(Size, frameSize, RandomFrameInvolidList)
    {
      Size=size;
      debug_Flag(std::clog);
    }
#endif

