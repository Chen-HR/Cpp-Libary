namespace LogicGate
  {
    #define Template_1Type template <class Type1>
    #define Template_2Type template <class Type1, class Type2>
    #define _1Input Type1 input1
    #define _2Input Type1 input1, Type2 input2
    Template_1Type bool NOT  (_1Input) { return !((bool)(input1)); }
    Template_1Type bool AND  (Type1 input1, Type1 input2) { return  (((bool)(input1))&&((bool)(input2))); }
    Template_1Type bool NAND (Type1 input1, Type1 input2) { return !(((bool)(input1))&&((bool)(input2))); }
    Template_1Type bool OR   (Type1 input1, Type1 input2) { return  (((bool)(input1))||((bool)(input2))); }
    Template_1Type bool NOR  (Type1 input1, Type1 input2) { return !(((bool)(input1))||((bool)(input2))); }
    Template_1Type bool XOR  (Type1 input1, Type1 input2) { return  ((((bool)(input1))&&(!((bool)(input2))))||((!((bool)(input1)))&&((bool)(input2)))); }
    Template_1Type bool NXOR (Type1 input1, Type1 input2) { return !((((bool)(input1))&&(!((bool)(input2))))||((!((bool)(input1)))&&((bool)(input2)))); }
  }

#include <iostream>
#include <iomanip>
#include <cmath>

namespace Digital
  {
    using namespace LogicGate;
    Template_1Type struct DataTuple_2
      {
        Type1 data1=false;
        Type1 data2=false;
      };
    Template_1Type void print_DataTuple_2(Digital::DataTuple_2<Type1>& Tuple)
      { std::cout<<"("<<Tuple.data1<<","<<Tuple.data2<<")"; }
    namespace Sequential
      {
        namespace Latches
          {
            namespace SetRset
              {
                Template_1Type DataTuple_2 <bool> SR_NOR (Type1 input1, Type1 input2, bool output1=false, bool output2=false, unsigned long long int step=10, bool printPath=false)
                  {
                    Digital::DataTuple_2<bool> output;
                    output.data1=output1;
                    output.data2=output2;
                    if (printPath) {std::cout<<std::setw(log10(step)+1)<<0<<": "; Digital::print_DataTuple_2<Type1>(output); std::cout<<std::endl;}
                    for (unsigned long long int index=0; index<step; index++)
                      {
                        output.data1=NOR(input1, output2);
                        output.data2=NOR(input2, output1);
                        output1=output.data1;
                        output2=output.data2;
                        if (printPath) {std::cout<<std::setw(log10(step)+1)<<index+1<<": "; Digital::print_DataTuple_2<Type1>(output); std::cout<<std::endl;}
                      }
                    return output;
                  }
                Template_1Type DataTuple_2 <bool> SR_NAND (Type1 input1, Type1 input2, bool output1=false, bool output2=false, unsigned long long int step=10, bool printPath=false)
                  {
                    Digital::DataTuple_2<bool> output;
                    output.data1=output1;
                    output.data2=output2;
                    if (printPath) {std::cout<<std::setw(log10(step)+1)<<0<<": "; Digital::print_DataTuple_2<Type1>(output); std::cout<<std::endl;}
                    for (unsigned long long int index=0; index<step; index++)
                      {
                        output.data1=NAND(input1, output2);
                        output.data2=NAND(input2, output1);
                        output1=output.data1;
                        output2=output.data2;
                        if (printPath) {std::cout<<std::setw(log10(step)+1)<<index+1<<": "; Digital::print_DataTuple_2<Type1>(output); std::cout<<std::endl;}
                      }
                    return output;
                  }
              }
            Template_1Type DataTuple_2 <bool> SetReset_ (bool (*logicGate)(Type1,bool), Type1 input1, Type1 input2, bool output1=false, bool output2=false, unsigned long long int step=10, bool printPath=false)
              {
                Digital::DataTuple_2<bool> output;
                output.data1=output1;
                output.data2=output2;
                if (printPath) {std::cout<<std::setw(log10(step)+1)<<0<<": "; Digital::print_DataTuple_2<Type1>(output); std::cout<<std::endl;}
                for (unsigned long long int index=0; index<step; index++)
                  {
                    output.data1=logicGate(input1, output2);
                    output.data2=logicGate(input2, output1);
                    output1=output.data1;
                    output2=output.data2;
                    if (printPath) {std::cout<<std::setw(log10(step)+1)<<index+1<<": "; Digital::print_DataTuple_2<Type1>(output); std::cout<<std::endl;}
                  }
                return output;
              }
          }
        namespace FlipFlop
          {}
      }
    
  }

