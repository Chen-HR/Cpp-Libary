#include "Debug.hpp"
#include <random>
#include <chrono>
#include <algorithm>
#include "Processor.h"
#ifndef SystemMemoryFrame_hpp
  #include "SystemMemoryFrame.hpp"
#endif
#ifndef SystemMemoryFrame_cpp
  #define SystemMemoryFrame_cpp
  
  SystemMemoryFrame::SystemMemoryFrame(SystemMemoryFrame& systemMemoryFrame) 
    : Size(systemMemoryFrame.Size), Number(systemMemoryFrame.Number), InvolidList(systemMemoryFrame.InvolidList)
    {}
  SystemMemoryFrame::SystemMemoryFrame(std::size_t systemMemorySize, std::size_t size, bool RandomInvolidList=true) 
    : Size(size), Number(systemMemorySize/Size)
    {
      debug_Flag(std::clog);
      for (std::size_t index = 0; index < Number; index++) 
        {
          SystemMemoryFrameTableData* buffer = new SystemMemoryFrameTableData(index);
          InvolidList.push_back(buffer);
          // FrameTable[buffer->ID]=*buffer;
          // FrameTable.push_back(buffer);
        }
      if (RandomInvolidList)
        { // std::random_shuffle(InvolidList.begin(), InvolidList.end());
          /** @brief Random Number Generator */ 
          std::mt19937 RandomNumberGenerator(std::chrono::system_clock::now().time_since_epoch().count());
          /** @brief Random sort using insertion sort */ 
          for (std::size_t index = 0; index < Number; index++)
            /** @brief Randomly obtain one of the values ​​of the unprocessed block to the current processing position */ 
            Processor::exchange(*std::next(InvolidList.begin(), index), *std::next(InvolidList.begin(), (*(new std::uniform_int_distribution<size_t>(index, Number-1)))(RandomNumberGenerator)));
        }
      debug_Flag(std::clog);
    }
#endif

