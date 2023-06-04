// File : 
//   Maker : "NUU.EECS.CSIE.109.043"(U0924043)
#include "Processor.h"
namespace Math
  {
    // Declear and define function indexCalculator
    // indexCalculator(n,i) >> n^i = n ¡P n ¡P n ¡P ¡K ¡P n = pi (integer i=(1 to n)) { x }
    template <class ReturnType, class InputType, class IndexType> ReturnType indexCalculator(InputType number, IndexType index)
      {
        // Create a number for result answer
        ReturnType result=1;
        // Calculate the index
        for (int i=0;i<number;i++)
          result*=number;
        // Return result
        return result;
      }
    // Declear and define function factorial
    // factorial(n) >> n! = n ¡P (n ¡V 1) ¡P (n ¡V 2) ¡P ¡K ¡P 1
    template <class ReturnType> ReturnType factorial(ReturnType number)
      {
        // Create a number for result answer
        ReturnType result=1;
        // Calculate the factorial
        for (ReturnType i=1;i<=number;i+=1)
          result*=i;
        // Return result
        return result;
      }
    // Declear and define function naturalLogarithm
    // naturalLogarithm(n,i) >> e^i = 1 + ( x^1 / 1! ) + ( x^2 / 2! ) + ( x^3 / 3!) + ... + ( x^i / i!) = sigma(integer i=(0 to n)) { ( x^i / i! ) }
    template <class ReturnType, class AccuracyType, class IndexType> ReturnType naturalLogarithm(AccuracyType number=10, IndexType index=1)
      {
        // Create a number for result answer
        ReturnType result=0;
        // Calculate the factorial
        for (ReturnType i=0;i<=number;i+=1)
          result+=(indexCalculator(index,i))/(factorial(i));
        // Return result
        return result;
      }
    // Absolute
    template <class Number> void absolute(Number& n) {if (n<0) n*=-1;}
    // Get the greatest common divisor of a and b
    template <class Number> Number gcd_iteration(Number a,Number b)
      {
        if (a<b) Processor::exchange(a,b);
        while (b!=0) {Number c = a % b; a = b, b = c;}
        return a;
      }
    template <class Number> Number gcd_recursive(Number a,Number b)
      {
        if (a< b) Processor::exchange(a,b);
        if (b==0) return a;
        return gcd_recursive(b,a%b);
      }
    template <class Number> Number gcd(Number a,Number b,bool recursive=false)
      {
        absolute(a),absolute(b);
        if (recursive)
          return gcd_recursive(a,b);
        else
          return gcd_iteration(a,b);
      }
  }