
#ifndef LogicGate_hpp
  #define LogicGate_hpp
  namespace LogicGate
    {
      template <class Type> Type  NOT(Type& a);
      template <class Type> Type  AND(Type& a,Type& b);
      template <class Type> Type NAND(Type& a,Type& b);
      template <class Type> Type   OR(Type& a,Type& b);
      template <class Type> Type  NOR(Type& a,Type& b);
      template <class Type> Type  XOR(Type& a,Type& b);
      template <class Type> Type NXOR(Type& a,Type& b);
    }
#endif //LogicGate_hpp
#ifndef LogicGate_cpp
  #include "LogicGate.cpp"
#endif //LogicGate_cpp