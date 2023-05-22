// #include <bitset>
#include <iostream>
#include <cstring>
#include <ostream>
#include <fstream>
#include <sstream>
#include "Log.hpp"
#ifndef Stream_Out_hpp
  #include "Stream_Out.hpp"
#endif //Stream_Out_hpp
#ifndef Stream_Out_cpp
  #define Stream_Out_cpp
  template<class CharacterType> Stream_Out::Std_OutStream<CharacterType>::Std_OutStream()
    {
      this->file = "OutStream_String";
    }
  template<class CharacterType> Stream_Out::Std_OutStream<CharacterType>::Std_OutStream(Stream_Out::Std_OutStream<CharacterType>::_ostream_console& stream)
    {
      this->file = "OutStream_Console";
    }
  template<class CharacterType> Stream_Out::Std_OutStream<CharacterType>::Std_OutStream(const char* filePath)
    {
      this->file = std::strcpy(this->file, filePath);
    }
#endif //Stream_Out_cpp