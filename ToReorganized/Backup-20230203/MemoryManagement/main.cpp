#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <random>
#include <list>
#include <chrono>
#include "Debug.hpp"
#include "System.hpp"
// #include "Process.hpp"

template <typename Type> Type stdcin()
  {
    Type result;
    std::cin>>result;
    return result;
  }

template <typename Type> Type stdcin(const char* InputHint, bool (*isInvalidValue)(Type), char* Prefix=(char*)(""), std::size_t shift=0)
  {
    Type result; 
    bool InputError = true; while (InputError)
      {
        std::cout<<InputHint; std::cin>>result;
        InputError = false;
        if (!std::cin) 
          {
            InputError = true;
              std::cerr<<"  ERROR: Unrecognized input."<<std::endl;
              std::cin.clear();
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
          }
        if (isInvalidValue(result)) 
          {
            InputError = true;
              std::cerr<<"  ERROR: Invalid value detected: "<<result<<std::endl;
            continue;
          }
      }
    return result;
  }

int main(int argc, char const *argv[])
  {
    System system(*(new SystemMemory(
      stdcin<std::size_t>("Input System Memory Size: ", [](std::size_t buffer) -> bool {return (std::log2(buffer)-std::floor(std::log2(buffer)));}),
      stdcin<std::size_t>("Input System Memory Frame Size: " , [](std::size_t buffer) -> bool {return (std::log2(buffer)-std::floor(std::log2(buffer)));})
    )));
    debug_ObjectValue(std::clog, system.Memory.Size, "system.Memory.Size");\
    std::size_t ProcessNumber = stdcin<std::size_t>("Input Number of Process: ", [](std::size_t buffer) -> bool {return false;});
    for (std::size_t index = 0; index < ProcessNumber; index++) 
      {
        std::cout<<"  Infomation of Process["<<index<<"]: "<<std::endl;
        system.addProcess(
          stdcin<std::string>("Input Process Name: ", [](std::string buffer) -> bool {return false;}, (char*)"  ", 2),
          stdcin<std::size_t>("Input Process Memory Size: ", [](std::size_t buffer) -> bool {return false;}, (char*)"  ", 2),
          3
        );
        //debug_Flag(std::clog);
        // debug_ObjectValue(std::clog, system.Processes.back().Name, "system.Processes.back()");
        system.Processes.back().print((char*)"  ", 2);
      }
    while (true)
      {
        system.physicalAddress(
          stdcin<std::string>("Enter itinerary and Virtual Address: ", [](std::string buffer) -> bool {return false;}, (char*)"  ", 2),
          stdcin<std::size_t>("", [](std::size_t buffer) -> bool {return false;}, (char*)"", 0)
        );
      }
    
    std::cout<<"main: Finish."<<std::endl;
    return 0;
  }