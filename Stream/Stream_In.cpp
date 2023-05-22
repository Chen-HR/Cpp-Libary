// #include <bitset>
#include "Log.hpp"
#ifndef Stream_In_hpp
  #include "Stream_In.hpp"
#endif //Stream_In_hpp
#ifndef Stream_In_cpp
  #define Stream_In_cpp
  template <typename ReturnType> ReturnType Stream_In::stdcin()
    {
      ReturnType result;
      std::cin >> result;
      return result;
    }

  template <typename ReturnType> ReturnType Stream_In::stdcin(const char* InputHint, bool (*isInvalidValue)(ReturnType), char* Prefix=(char*)(""), std::size_t shift=0)
    {
      ReturnType result; 
      bool InputError = true; while (InputError)
        {
          std::cout << InputHint; std::cin >> result;
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
  
  
#endif //Stream_In_cpp