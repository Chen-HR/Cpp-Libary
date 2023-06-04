// File : 
//   Maker : "NUU.EECS.CSIE.109.043"(U0924043)
namespace Processor
  {
    #include<time.h>
    const double timeUnit = double(CLOCKS_PER_SEC)/1000.0; // 1(ms), \n(1000(ms)=1(s))
    template <class ReturnType, class FuncType, class ArguType1> 
      ReturnType runTime(FuncType (*narrative)(ArguType1),ArguType1 Argu1)
      {
        double startTime = double(clock())/timeUnit;
        ((*narrative)(Argu1));
        double endTime   = double(clock())/timeUnit;
        return (endTime-startTime);
      }
    template <class ReturnType, class FuncType, class ArguType1, class ArguType2> 
      ReturnType runTime(FuncType (*narrative)(ArguType1,ArguType2),ArguType1 Argu1,ArguType2 Argu2)
      {
        double startTime = double(clock())/timeUnit;
        ((*narrative)(Argu1,Argu2));
        double endTime   = double(clock())/timeUnit;
        return (endTime-startTime);
      }
    template <class ReturnType, class FuncType, class ArguType1, class ArguType2, class ArguType3> 
      ReturnType runTime(FuncType (*narrative)(ArguType1,ArguType2,ArguType3),ArguType1 Argu1,ArguType2 Argu2,ArguType3 Argu3)
      {
        double startTime = double(clock())/timeUnit;
        ((*narrative)(Argu1,Argu2,Argu3));
        double endTime   = double(clock())/timeUnit;
        return (endTime-startTime);
      }
    // Exchange content of a and b
    template <class Type> void exchange(Type& a,Type& b)
      {
        Type c = a;
        a = b, b = c;
      }
  }