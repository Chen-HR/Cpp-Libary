// #include <bitset>
#include "Log.hpp"
#ifndef Process_hpp
  #include "Process.hpp"
#endif //Process_hpp
#ifndef Process_cpp
  #define Process_cpp
  template <class Type> inline void Process::exchange(Type& a,Type& b)
    {
      Type c = a;
      a = b, b = c;
    }
  
  
#endif //Process_cpp