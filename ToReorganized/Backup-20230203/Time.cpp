#include "Time.Cpp-Libary"
#include <iostream>
int main()
  {
    for (int i=0;i<10;i++,std::printf("%10ld\n",std::clock()/1000),Time::Delay(500));
  }