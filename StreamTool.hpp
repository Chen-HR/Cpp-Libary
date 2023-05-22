#ifndef StreamTool_hpp
  #define StreamTool_hpp
  // class StreamDeploy
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
  #ifndef StreamTool_cpp
    #include "StreamTool.cpp"
  #endif
#endif