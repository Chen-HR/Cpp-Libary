#include "OutStream.hpp"

int main() 
  {
    OutStream_16 ostream_string ;
    OutStream_16 ostream_console(std::wcout);
    OutStream_16 ostream_file   ("D:\\Studio\\Programming\\Language\\CCpp\\Library\\test.txt", std::ios::app);
    ostream_string () << ostream_string .infomation() << std::endl;
    ostream_console() << ostream_console.infomation() << std::endl;
    ostream_file   () << ostream_file   .infomation() << std::endl;
    ostream_console() << ostream_string .content() << std::endl;
  }

