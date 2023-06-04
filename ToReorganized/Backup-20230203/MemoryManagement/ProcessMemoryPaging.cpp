#include "Debug.hpp"
#include <iomanip>
#include <cmath>
#ifndef ProcessMemoryPaging_hpp
  #include "ProcessMemoryPaging.hpp"
#endif
#ifndef ProcessMemoryPaging_cpp
  #define ProcessMemoryPaging_cpp
  ProcessMemoryPaging::ProcessMemoryPaging(ProcessMemoryPaging& processMemoryPaging) 
    : Number(processMemoryPaging.Number), Frame(processMemoryPaging.Frame), PagingTable(processMemoryPaging.PagingTable)
    {
    }
  ProcessMemoryPaging::ProcessMemoryPaging(std::size_t processMemorySize, SystemMemoryFrame& systemMemoryFrame) 
    : Number(processMemorySize/systemMemoryFrame.Size), Frame(systemMemoryFrame)
    {
      debug_Flag(std::clog);
      for (std::size_t index = 0; index < Number; index++) 
        {
          ProcessMemoryPagingTableData* buffer = new ProcessMemoryPagingTableData(index);
          PagingTable.push_back(buffer);
        }
      debug_Flag(std::clog);
    }
  void ProcessMemoryPaging::deploy(std::size_t pageId)
    {
      (*std::next(PagingTable.begin(), pageId))->Volid = true;
      (*std::next(PagingTable.begin(), pageId))->SystemMemoryFrame_ID = Frame.InvolidList.front()->ID;
      Frame.InvolidList.front()->Volid = true;
      Frame.InvolidList.pop_front();
    }
   void ProcessMemoryPaging::print(char* Prefix=(char*)(""), std::size_t shift=0, std::ostream& stream=std::cout)
    {
      for (std::size_t index = 0; index <  shift; index++) {stream<<Prefix;} stream<<"Process's Memory Paging Number: "<<Number<<std::endl; 
      for (std::size_t index = 0; index <  shift; index++) {stream<<Prefix;} stream<<"Process's Memory Paging Size: "<<Frame.Size<<std::endl;
      for (std::size_t index = 0; index <  shift; index++) {stream<<Prefix;} stream<<"Process's Memory Paging Table: "; 
      for (std::size_t index = 0; index <= shift; index++) {stream<<Prefix;} stream<<"Page  : ["; 
      for (std::size_t index = 0; index < Number; index++) {stream<<std::setw(std::log10(Frame.Size))<<(*std::next(PagingTable.begin(), index))->ID                   <<", ";}
      stream<<"\b\b]"<<std::endl;
      for (std::size_t index = 0; index <= shift; index++) {stream<<Prefix;} stream<<"Frame : ["; 
      for (std::size_t index = 0; index < Number; index++) {stream<<std::setw(std::log10(Frame.Size))<<(*std::next(PagingTable.begin(), index))->SystemMemoryFrame_ID <<", ";} 
      stream<<"\b\b]"<<std::endl;
      for (std::size_t index = 0; index <= shift; index++) {stream<<Prefix;} stream<<"Volid : [";
      for (std::size_t index = 0; index < Number; index++) {stream<<std::setw(std::log10(Frame.Size))<<(*std::next(PagingTable.begin(), index))->Volid                <<", ";}
      stream<<"\b\b]"<<std::endl;
    }
#endif

