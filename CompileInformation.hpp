
#include <iomanip>
#include <string>
#ifndef CompileInformation_hpp
  #define CompileInformation_hpp
  // namespace CompileInformation
  //   {
  //     template <class Type> Type  NOT(Type& a);
  //     template <class Type> Type  AND(Type& a,Type& b);
  //     template <class Type> Type NAND(Type& a,Type& b);
  //     template <class Type> Type   OR(Type& a,Type& b);
  //     template <class Type> Type  NOR(Type& a,Type& b);
  //     template <class Type> Type  XOR(Type& a,Type& b);
  //     template <class Type> Type NXOR(Type& a,Type& b);
  //   }
  #define CompileInformation(stream) stream << "Compile Information: " << std::endl << "  C++ standard: C++" << (std::to_string(__cplusplus)).substr(2, 2) << std::endl << "  file        : " << __FILE__ << std::endl << "  date        : " << __DATE__ << std::endl << "  time        : " << __TIME__ << std::endl
#endif //CompileInformation_hpp
#ifndef CompileInformation_cpp
  #include "CompileInformation.cpp"
#endif //CompileInformation_cpp