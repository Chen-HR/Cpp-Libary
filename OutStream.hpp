#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>


#ifndef OutStream_hpp
  #define OutStream_hpp
  // class OutStream 
  //   {
  //     private:
  //     protected:
  //       const char* type;
  //       char* file;
  //     public:
  //       std::ostream* main;
  //       OutStream();
  //       OutStream(std::ostream&);
  //       OutStream(const char*, std::ios_base::openmode);
  //       std::string str();
  //       std::ostream& operator()();
  //       ~OutStream();
  //   };
  template <class CharacterType> class OutStream 
    {
      private:
      protected:
        const char* type;
        char* file;
      public:
        using _ostream_console = std::basic_ostream<CharacterType, std::char_traits<CharacterType>>;
        using _ostream_file    = std::basic_ofstream<CharacterType, std::char_traits<CharacterType>>;
        using _ostream_string  = std::basic_ostringstream<CharacterType, std::char_traits<CharacterType>, std::allocator<CharacterType>>;
        using _string = std::basic_string<CharacterType, std::char_traits<CharacterType>, std::allocator<CharacterType>>;
        _ostream_console* main;
        OutStream();
        OutStream(_ostream_console&);
        OutStream(const char*);
        OutStream(const char*, std::ios_base::openmode);
        _string content();
        _string infomation();
        _ostream_console& to_ostream_console();
        _ostream_file&    to_ostream_file   ();
        _ostream_string&  to_ostream_string ();
        _ostream_console& operator()();
        ~OutStream();
    };
  typedef OutStream<char> OutStream_8;
  typedef OutStream<wchar_t> OutStream_16;
#endif //OutStream_hpp
#ifndef OutStream_cpp
  #include "OutStream.cpp"
#endif //OutStream_cpp