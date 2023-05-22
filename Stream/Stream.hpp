#include <istream>
#include <ostream>
#include <fstream>
#include <sstream>

// std::ofstream
#ifndef Stream_hpp
  #define Stream_hpp
  namespace Stream
    {
      #ifndef Stream_Out_hpp
        #include "Stream_Out.hpp"
      #endif //Stream_Out_hpp
      #ifndef Stream_In_hpp
        #include "Stream_In.hpp"
      #endif //Stream_In_hpp
      class StreamTool
        {
          private:
          protected:
          public:
            char* Indentation;
            bool  nameEnable;
            bool  stdoutEnable;
            bool  stdlogEnable;
            bool  stderrEnable;
            StreamTool(char*, bool, bool, bool, bool);
            StreamTool(char*, short);
            StreamTool setStreamTool(char*, bool, bool, bool, bool);
            StreamTool setStreamTool(char*, short);
            template <class Type> inline Type stdinReader();
            template <class DescriptionType, class IndentationType, class IndentationLevelType> 
              void putDescription(DescriptionType, IndentationType, IndentationLevelType, bool);
            template <class ValueType, class DescriptionType, class IndentationType, class IndentationLevelType> 
              void getValueWithDescription(ValueType&, DescriptionType, IndentationType, IndentationLevelType);
        };
    }
#endif //Stream_hpp
#ifndef Stream_cpp
  #include "Stream.cpp"
#endif //Stream_cpp