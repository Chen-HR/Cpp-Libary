#ifndef DEBUG_HPP
  #define DEBUG_HPP
  #define debug_Flag(stream) stream<<"Debug: \n  {\n    File: \""<<__FILE__<<"\", \n    Line: "<<__LINE__<<"\n  }"<<std::endl
  #define debug_Massage(stream, massage) stream<<"Debug: \n  {\n    File: \""<<__FILE__<<"\", \n    Line: "<<__LINE__<<", \n    Massage: "<<massage<<"\n  }"<<std::endl
  #define debug_ObjectAddress(stream, object, description) stream<<"Debug: \n  {\n    File: \""<<__FILE__<<"\", \n    Line: "<<__LINE__<<", \n    Description: "<<description<<", \n    Address: "<<&object<<"\n  }"<<std::endl
  #define debug_ObjectValue(stream, object, description) stream<<"Debug: \n  {\n    File: \""<<__FILE__<<"\", \n    Line: "<<__LINE__<<", \n    Description: "<<description<<", \n    Value: "<<object<<"\n  }"<<std::endl
#endif