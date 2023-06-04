#include "Debug.hpp"
#ifndef Process_hpp
  #include "Process.hpp"
#endif
// #include "Processor.h"
#ifndef Process_cpp
  #define Process_cpp
  Process::Process(std::size_t id, std::string name, std::size_t processMemorySize, SystemMemory* systemMemory, std::size_t initialDeployNumber=0)
    : ID(id), Name(name), ProcessMemory_(processMemorySize, systemMemory->Frame), SystemMemory_(systemMemory)
    {
      // debug_Flag(std::clog);
      for (std::size_t index = 0; index < initialDeployNumber; index++) {debug_Flag(std::clog);deploy(index);}
    }
  void Process::deploy(std::size_t pageId)
    {
      // (*std::next(ProcessMemory_.Paging.PagingTable.begin(), pageId))->Volid = true;
      // (*std::next(ProcessMemory_.Paging.PagingTable.begin(), pageId))->SystemMemoryFrame_ID = SystemMemory_->Frame.InvolidList.front()->ID;
      // SystemMemory_->Frame.InvolidList.front()->Volid = true;
      // SystemMemory_->Frame.InvolidList.pop_front();
      ProcessMemory_.deploy(pageId);
    }
  void Process::print(char* Prefix=(char*)(""), std::size_t shift=0, std::ostream& stream=std::cout)
    {
      // debug_Flag(std::clog);
      for (std::size_t index = 0; index <  shift; index++) {stream<<Prefix;} stream<<"Process's ID: "<<ID<<std::endl;
      for (std::size_t index = 0; index <  shift; index++) {stream<<Prefix;} stream<<"Process's Name: "<<Name<<std::endl;
      ProcessMemory_.print(Prefix, shift+1);
    }
  std::size_t Process::physicalAddress(std::size_t virtualAddress, bool printCalculationProcess=false, bool newline=false, char* Prefix=(char*)(""), std::size_t shift=0, std::ostream& stream=std::cout)
    {
      print((char*)"  ", 2);
      return ProcessMemory_.physicalAddress(virtualAddress, printCalculationProcess, newline, Prefix, shift, stream);
    }
#endif

