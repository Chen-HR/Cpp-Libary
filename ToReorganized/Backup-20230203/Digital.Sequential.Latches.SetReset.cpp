#include <string>
#include <iostream>
#include "LogicGate.h"


int main()
  {
    while (true)
      {
        std::string gate="";
        unsigned long long int num=0;
        bool I1=false, I2=false, O1=false, O2=false, print=false;
        std::cout<<"\n\ngate I1 I2 O1 O2 num print << "; std::cin>>gate>>I1>>I2>>O1>>O2>>num>>print;
        std::cout<<"::Digital::Sequential::Latches::SetReset("<<gate<<","<<I1<<","<<I2<<","<<O1<<","<<O2<<","<<num<<","<<print<<"):"<<std::endl;
        if (gate=="AND" ) ::Digital::Sequential::Latches::SetReset_ <bool>(&::LogicGate::AND ,I1,I2,O1,O2,num,print);
        if (gate=="NAND") ::Digital::Sequential::Latches::SetReset_ <bool>(&::LogicGate::NAND,I1,I2,O1,O2,num,print);
        if (gate=="OR"  ) ::Digital::Sequential::Latches::SetReset_ <bool>(&::LogicGate::OR  ,I1,I2,O1,O2,num,print);
        if (gate=="NOR" ) ::Digital::Sequential::Latches::SetReset_ <bool>(&::LogicGate::NOR ,I1,I2,O1,O2,num,print);
        if (gate=="XOR" ) ::Digital::Sequential::Latches::SetReset_ <bool>(&::LogicGate::XOR ,I1,I2,O1,O2,num,print);
        if (gate=="NXOR") ::Digital::Sequential::Latches::SetReset_ <bool>(&::LogicGate::NXOR,I1,I2,O1,O2,num,print);
      }
  }