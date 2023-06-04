#include "Debug.hpp"
#include <cstring>
#ifndef ProcessMemory_hpp
  #include "ProcessMemory.hpp"
#endif
#ifndef ProcessMemory_cpp
  #define ProcessMemory_cpp
  ProcessMemory::ProcessMemory(ProcessMemory& processMemory) 
    : Size(processMemory.Size), Paging(processMemory.Paging), Frame(processMemory.Frame)
    {debug_Flag(std::clog);}
  ProcessMemory::ProcessMemory(std::size_t processMemorySize, SystemMemoryFrame& systemMemoryFrame) 
    : Size(processMemorySize), Paging(processMemorySize, Frame), Frame(systemMemoryFrame)
    {debug_Flag(std::clog);}
  void ProcessMemory::deploy(std::size_t pageId)
    {
      // (*std::next(Paging.PagingTable.begin(), pageId))->Volid = true;
      // (*std::next(Paging.PagingTable.begin(), pageId))->SystemMemoryFrame_ID = Frame.InvolidList.front()->ID;
      // Frame.InvolidList.front()->Volid = true;
      // Frame.InvolidList.pop_front();
      // debug_Flag(std::clog);
      Paging.deploy(pageId);
    }
  void ProcessMemory::print(char* Prefix=(char*)(""), std::size_t shift=0, std::ostream& stream=std::cout)
    {
      for (std::size_t index = 0; index <  shift; index++) {stream<<Prefix;} stream<<"Process's Memory Size: "<<Size<<std::endl; 
      Paging.print(Prefix, shift+1);
    }
  std::size_t ProcessMemory::physicalAddress(std::size_t virtualAddress, bool printCalculationProcess=false, bool newline=false, char* Prefix=(char*)(""), std::size_t shift=0, std::ostream& stream=std::cout)
    {
      std::size_t pageId = virtualAddress/Frame.Size;
      if (!((*std::next(Paging.PagingTable.begin(), pageId))->Volid)) deploy(pageId);
      if (printCalculationProcess)
        {
          if (newline) 
            {
              stream<<std::endl;
              for (std::size_t index = 0; index <= shift; index++) {stream<<Prefix;}
              stream<<"  ";
            }
          stream<<"("<<((*std::next(Paging.PagingTable.begin(), pageId))->SystemMemoryFrame_ID)<<"*"<<Frame.Size<<")+"
                <<"("<<virtualAddress<<"-("<<((*std::next(Paging.PagingTable.begin(), pageId))->ID)<<"*"<<Frame.Size<<"))";
          if (newline) 
            {
              stream<<std::endl;
              for (std::size_t index = 0; index <  shift; index++) {stream<<Prefix;}
              stream<<"= ";
            }
          stream<<"("<<((*std::next(Paging.PagingTable.begin(), pageId))->SystemMemoryFrame_ID)*Frame.Size<<")+"
                <<"("<<virtualAddress<<"-("<<((*std::next(Paging.PagingTable.begin(), pageId))->ID)*Frame.Size<<"))";
          if (newline) 
            {
              stream<<std::endl;
              for (std::size_t index = 0; index <  shift; index++) {stream<<Prefix;}
              stream<<"= ";
            }
          stream<<"("<<((*std::next(Paging.PagingTable.begin(), pageId))->SystemMemoryFrame_ID)*Frame.Size<<")+"
                <<"("<<virtualAddress-(((*std::next(Paging.PagingTable.begin(), pageId))->ID)*Frame.Size)<<")";
          if (newline) 
            {
              stream<<std::endl;
              for (std::size_t index = 0; index <  shift; index++) {stream<<Prefix;}
              stream<<"= ";
            }
          stream<<(((*std::next(Paging.PagingTable.begin(), pageId))->SystemMemoryFrame_ID)*Frame.Size)+(virtualAddress-(((*std::next(Paging.PagingTable.begin(), pageId))->ID)*Frame.Size));
          if (newline) 
            {
              stream<<std::endl;
              for (std::size_t index = 0; index <  shift; index++) {stream<<Prefix;}
            }
        }
      return (((*std::next(Paging.PagingTable.begin(), pageId))->SystemMemoryFrame_ID)*Frame.Size)+(virtualAddress-(((*std::next(Paging.PagingTable.begin(), pageId))->ID)*Frame.Size));
    }
#endif

