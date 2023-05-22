
#ifndef LogicGate_hpp
  #include "LogicGate.hpp"
#endif //LogicGate_hpp
#ifndef LogicGate_cpp
  #define LogicGate_cpp
  template <class Type> Type LogicGate:: NOT(Type& a) { return !a; }
  template <class Type> Type LogicGate:: AND(Type& a,Type& b) { return  (a&b); }
  template <class Type> Type LogicGate::NAND(Type& a,Type& b) { return !(a&b); }
  template <class Type> Type LogicGate::  OR(Type& a,Type& b) { return  (a|b); }
  template <class Type> Type LogicGate:: NOR(Type& a,Type& b) { return !(a|b); }
  template <class Type> Type LogicGate:: XOR(Type& a,Type& b) { return  (a^b); }
  template <class Type> Type LogicGate::NXOR(Type& a,Type& b) { return !(a^b); }
#endif //LogicGate_cpp