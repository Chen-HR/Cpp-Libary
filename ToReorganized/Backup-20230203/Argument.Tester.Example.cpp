#include <iostream>
#include "Arguments.Cpp-Libary"
void _Argument_Reader_Tester_01(void* Argument1,...)
  {
    std::cout << "        " << "    " << &Argument1 << " -> " << Argument1 << " : " << *((int*)( Argument1)) << std::endl;
    // Declare ArgumentList
    //void** ArgumentList = &Argument1;
    //decltype(Argument1)* ArgumentList = &Argument1;
    decltype(Argument1)* ArgumentList = &Argument1;
    for (int i=0;i<10;i++)
      {
        std::cout << &ArgumentList << " -> " <<  (ArgumentList+i) << " -> " << *(ArgumentList+i) << " : " << (*((int*)(*(ArgumentList+i)))) << std::endl;
      }
  }
void _Argument_Reader_Tester_02(void* Argument1,...)
  {
    void** ArgumentList = 0;
    //std::cout << "        " << "    " << &Argument1 << " -> " << Argument1 << " : " << *((int*)( Argument1)) << std::endl;
    //std::cout << &ArgumentList << " -> " <<  (ArgumentList+0) << " -> " << *(ArgumentList+0) << " : " << (*((int*)(*(ArgumentList+0)))) << std::endl;
    Argument::Set(ArgumentList,Argument1);
    for (int i=0;i<10;i++)
      {
        int Data = 0;
        Data = Argument::GetValue(ArgumentList,i,Data);
        std::cout << Data << std::endl;
      }
  }
void _Argument_Reader_Tester_03(void* Argument1,...)
  {
    Argument::Argument ArgumentList(Argument1);
    for (int i=0;i<10;i++)
      {
        int Data = ArgumentList.GetValue<int,int>(i);
        std::cout << ArgumentList.GetPath(i) << " : " << Data << std::endl;
      }
  }
void _Argument_Reader_Tester_04(void* Argument1,...)
  {
    Argument::Argument ArgumentList(Argument1);
    for (int i=0;i<10;i++)
      {
        int Data = 0;
        Data = ArgumentList.GetValue(i,Data=0);
        std::cout << ArgumentList.GetPath(i) << " : " << Data << std::endl;
      }
  }
void _Argument_Reader_Tester_05(void* Argument1,...)
  {
    Argument::Argument ArgumentList(Argument1);
    for (int i=0;i<10;i++)
      {
        int Data = 0;
        Data =  ArgumentList.GetValue(i,Data=0);
        void* Path = ArgumentList.GetPath(i);
        std::cout << Path << " : " << Data << std::endl;
      }
  }
int main()
  {
    int V[10]={0,1,2,3,4,5,6,7,8,9};
    _Argument_Reader_Tester_04(&(V[0]),&(V[1]),&(V[2]),&(V[3]),&(V[4]),&(V[5]),&(V[6]),&(V[7]),&(V[8]),&(V[9]));
  }