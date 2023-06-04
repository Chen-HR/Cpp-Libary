#include <iostream>

#ifndef StreamTool_hpp
  #include "StreamTool.hpp"
#endif
#ifndef StreamTool_cpp
  #define StreamTool_cpp
  StreamTool::StreamTool(char* Indentation_, bool nameEnable_, bool stdoutEnable_, bool stdlogEnable_, bool stderrEnable_)
    : Indentation(Indentation_), nameEnable(nameEnable_), stdoutEnable(stdoutEnable_), stdlogEnable(stdlogEnable_), stderrEnable(stderrEnable_)
    {}
  StreamTool::StreamTool(char* Indentation_, short booleanList)
    : Indentation(Indentation_), nameEnable(booleanList&8), stdoutEnable(booleanList&4), stdlogEnable(booleanList&2), stderrEnable(booleanList&1)
    {}
  StreamTool StreamTool::setStreamTool(char* Indentation_, bool nameEnable_, bool stdoutEnable_, bool stdlogEnable_, bool stderrEnable_)
    {
      this->Indentation  = Indentation_ ;
      this->nameEnable   = nameEnable_  ;
      this->stdoutEnable = stdoutEnable_;
      this->stdlogEnable = stdlogEnable_;
      this->stderrEnable = stderrEnable_;
      return *this;
    }
  StreamTool StreamTool::setStreamTool(char* Indentation_, short booleanList)
    {
      this->Indentation  = Indentation_ ;
      this->nameEnable   = booleanList&8;
      this->stdoutEnable = booleanList&4;
      this->stdlogEnable = booleanList&2;
      this->stderrEnable = booleanList&1;
      return *this;
    }

  template <class Type> inline Type StreamTool::stdinReader()
    {
      Type buffer;
      std::cin>>buffer;
      return buffer;
    }

  template <class DescriptionType, class IndentationType, class IndentationLevelType> 
    void StreamTool::putDescription(DescriptionType Description, IndentationType Indentation, IndentationLevelType IndentationLevel, bool endLine)
      {
        if (this->stdoutEnable)
          {
            if (this->nameEnable) std::cout<<"stdout: ";
            for (IndentationLevelType index=0; index<IndentationLevel; index++) std::cout<<this->Indentation;
            std::cout<<Description; if (endLine) std::cout<<std::endl;
          }
        if (this->stdlogEnable)
          {
            if (this->nameEnable) std::clog<<"stdlog: ";
            for (IndentationLevelType index=0; index<IndentationLevel; index++) std::clog<<this->Indentation;
            std::clog<<Description; if (endLine) std::clog<<std::endl;
          }
        if (this->stderrEnable)
          {
            if (this->nameEnable) std::cerr<<"stderr: ";
            for (IndentationLevelType index=0; index<IndentationLevel; index++) std::cerr<<this->Indentation;
            std::cerr<<Description; if (endLine) std::cerr<<std::endl;
          }
      }
  template <class ValueType, class DescriptionType, class IndentationType, class IndentationLevelType>
    void StreamTool::getValueWithDescription(ValueType& Value, DescriptionType Description, IndentationType Indentation, IndentationLevelType IndentationLevel)
      {
        if (this->nameEnable) std::cout<<"stdout: ";
        for (IndentationLevelType index=0; index<IndentationLevel; index++) std::cout<<this->Indentation;
        std::cout<<Description; std::cin>>Value;
        if (stdoutEnable)
          {
            if (this->nameEnable) std::cout<<"stdout: ";
            for (IndentationLevelType index=0; index<IndentationLevel; index++) std::cout<<this->Indentation;
            std::cout<<Description<<Value<<std::endl;
          }
        if (this->stdlogEnable)
          {
            if (this->nameEnable) std::clog<<"stdlog: ";
            for (IndentationLevelType index=0; index<IndentationLevel; index++) std::clog<<this->Indentation;
            std::clog<<Description<<Value<<std::endl;
          }
        if (stderrEnable)
          {
            if (this->nameEnable) std::cerr<<"stderr: ";
            for (IndentationLevelType index=0; index<IndentationLevel; index++) std::cerr<<this->Indentation;
            std::cerr<<Description<<Value<<std::endl;
          }
      }
#endif