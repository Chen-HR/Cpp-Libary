#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"


int main(int argc, const char** argv)
  {
    std::cout<<"Integer size: "<<sizeof(size_t     )<<std::endl;
    std::cout<<"Random  size: "<<sizeof(std::rand())<<std::endl;
    std::cout<<"Integer Max : "<<SIZE_MAX<<std::endl;
    std::cout<<"Random  Max : "<<RAND_MAX<<std::endl;
    std::cout<<std::endl;
    
    size_t DataLength; std::cout<<"DataLength: "; std::cin>>DataLength;
    Array<size_t, size_t> array(DataLength);
    std::cout<<std::endl;

    std::srand(std::time(nullptr));
    for (size_t i=0; i<DataLength; i++) 
      array.setItem(i, std::rand());

    std::cout<<"Data: ["; 
    for (size_t i=0; i<DataLength; i++) 
      std::cout<<array[i]<<", "; 
    std::cout<<"\b\b]"<<std::endl<<std::endl;

  }