#include <iostream>
#include "Log.hpp"
#include "Stream.hpp"

int main()
  {
    Stream::Stream_Out::Std_OutStream<char> stream_string;
    Stream::Stream_Out::Std_OutStream<char> stream_console(std::cout);
    Stream::Stream_Out::Std_OutStream<char> stream_file("D:\\Studio\\Programming\\Language\\CCpp\\Library\\test.txt");
  }