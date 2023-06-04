#include "Random.h"
#include "Time.Cpp-Libary"
#include <iostream>

int main()
  {
    Random::setRandom();
    for (int i=0;i<20;i++)
      (std::cout<<Random::getRandom(10,100)<<std::endl),
      (Time::Delay(500));
  }
