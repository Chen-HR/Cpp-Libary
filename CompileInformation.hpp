#include <iomanip>
#ifndef CompileInformation_hpp
  #define CompileInformation_hpp

  #define CompileInformation_CppStd ((__cplusplus/100)%100)
  #define CompileInformation_Bit (sizeof(void*)*8)
  #define CompileInformation_File __FILE__
  #define CompileInformation_Date __DATE__
  #define CompileInformation_Time __TIME__

  #define CompileInformation_OutStream(stream) stream << "Compile Information: " << std::endl\
                                                      << "  C++ standard    : C++" << CompileInformation_CppStd << std::endl\
                                                      << "  bit architecture: " << CompileInformation_Bit << "-bit" << std::endl\
                                                      << "  file            : " << CompileInformation_File << std::endl\
                                                      << "  date            : " << CompileInformation_Date << std::endl\
                                                      << "  time            : " << CompileInformation_Time << std::endl
#endif //CompileInformation_hpp
#ifndef CompileInformation_cpp
  #include "CompileInformation.cpp"
#endif //CompileInformation_cpp