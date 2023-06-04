#include "Debug.hpp"
#include <string>
#include <exception>
#include "Container.hpp"
#define debug_Flag(stream) stream<<"Debug: \n  {\n    File: \""<<__FILE__<<"\", \n    Line: "<<__LINE__<<"\n  }"<<std::endl

#ifndef System_hpp
  #include "System.hpp"
#endif
#ifndef System_cpp
  #define System_cpp
  System::System(SystemMemory& memory) 
    : Memory(memory), NumberDispatchRecord(0)
    {}
  void System::addProcess(std::string processName, std::size_t processMemorySize, std::size_t initialDeployNumber =0)
    {
      debug_Flag(std::clog);
      try
        {
          // Processes.push_back(*(new Process(NumberDispatchRecord++, processName, processMemorySize, &Memory, initialDeployNumber )));
          debug_Flag(std::clog);
          auto* tmp = new Process(NumberDispatchRecord++, processName, processMemorySize, &Memory, initialDeployNumber );
          debug_Flag(std::clog);
          std::clog << tmp->Name<< std::endl;
        }
      catch(const std::exception& e)
        {
          std::cerr << e.what() << '\n';
        }
      debug_Flag(std::clog);
    }
  // std::size_t System::physicalAddress(std::size_t ProcessID  , std::size_t virtualAddress, bool printCalculationProcess=false, bool newline=false, char* Prefix=(char*)(""), std::size_t shift=0, std::ostream& stream=std::cout)
  //   {
  //     Container::select_pointer<std::list<Process>, Process, std::size_t>(Processes, ProcessID, [](Process& process, std::size_t& Process_ID) -> bool {return (process.ID==Process_ID);}) -> physicalAddress(virtualAddress, printCalculationProcess, newline, Prefix, shift, stream);
  //   }
  std::size_t System::physicalAddress(std::string ProcessName, std::size_t virtualAddress, bool printCalculationProcess=false, bool newline=false, char* Prefix=(char*)(""), std::size_t shift=0, std::ostream& stream=std::cout)
    {
      stream<<"  Page: ("            <<virtualAddress<<"/"<<Memory.Frame.Size<<") = "<<(virtualAddress/Memory.Frame.Size)<<std::endl;
      stream<<"  Physical Address: ";
      return Container::select_pointer<std::list<Process>, Process, std::string>(Processes, ProcessName, [](Process& process, std::string& ProcessName) -> bool {return (process.Name==ProcessName);}) -> physicalAddress(virtualAddress, true, true, "  ", 2, stream);
    }
#endif

