// #include <iostream>
// #include <sstream>
// #include <fstream>

#ifndef OutStream_hpp
  #include "OutStream.hpp"
#endif //OutStream_hpp
#ifndef OutStream_cpp
  #define OutStream_cpp
  // OutStream<CharacterType>::OutStream()
  //   : main(new std::ostringstream()) 
  //   { this->type = "OutStream_String"; }
  // OutStream<CharacterType>::OutStream(std::ostream& out) 
  //   : main(&out) 
  //   { this->type = "OutStream_Console"; }
  // OutStream<CharacterType>::OutStream(const char* filePath, std::ios_base::openmode mode = std::ios::out) 
  //   : main(new std::ofstream(filePath, mode)) 
  //   { this->type = "OutStream_File";
  //     this->file = ((char*)(std::malloc(std::strlen(filePath))));
  //     this->file = std::strcpy(this->file, filePath); 
  //   }
  // std::string OutStream<CharacterType>::str() 
  //   { 
  //     if (!(std::strcmp(this->type, "OutStream_String"))) return ((std::ostringstream*)(this->main))->str(); 
  //     return *(new std::string);
  //   }
  // std::ostream& OutStream<CharacterType>::operator()() 
  //   { return (*(this->main)); }
  // OutStream<CharacterType>::~OutStream() 
  //   {
  //     if (!(std::strcmp(this->type, "OutStream_String")))
  //       delete this->main;
  //     if (!(std::strcmp(this->type, "OutStream_File")))
  //       ((std::ofstream*)(this->main))->close(), delete this->main;
  //   }
  template <class CharacterType> OutStream<CharacterType>::OutStream()
    : main(new OutStream<CharacterType>::_ostream_string()) 
    { this->type = "OutStream_String"; 
      this->file = ((char*)(std::malloc(1))); this->file = std::strcpy(this->file, ""); 
    }
  template <class CharacterType> OutStream<CharacterType>::OutStream(typename OutStream<CharacterType>::_ostream_console& out) 
    : main(&out) 
    { this->type = "OutStream_Console"; 
      this->file = ((char*)(std::malloc(16)));
      if (&out == ((OutStream<CharacterType>::_ostream_console*)(&std::cout ))) this->file = std::strcpy(this->file, "std::cout"); 
      if (&out == ((OutStream<CharacterType>::_ostream_console*)(&std::clog ))) this->file = std::strcpy(this->file, "std::clog"); 
      if (&out == ((OutStream<CharacterType>::_ostream_console*)(&std::cerr ))) this->file = std::strcpy(this->file, "std::cerr"); 
      if (&out == ((OutStream<CharacterType>::_ostream_console*)(&std::wcout))) this->file = std::strcpy(this->file, "std::wcout"); 
      if (&out == ((OutStream<CharacterType>::_ostream_console*)(&std::wclog))) this->file = std::strcpy(this->file, "std::wclog"); 
      if (&out == ((OutStream<CharacterType>::_ostream_console*)(&std::wcerr))) this->file = std::strcpy(this->file, "std::wcerr"); 
    }
  template <class CharacterType> OutStream<CharacterType>::OutStream(const char* filePath) 
    : main(new OutStream<CharacterType>::_ostream_file(filePath)) 
    { this->type = "OutStream_File";
      this->file = ((char*)(std::malloc(std::strlen(filePath))));
      this->file = std::strcpy(this->file, filePath); 
    }
  template <class CharacterType> OutStream<CharacterType>::OutStream(const char* filePath, std::ios_base::openmode mode) 
    : main(new OutStream<CharacterType>::_ostream_file(filePath, mode)) 
    { this->type = "OutStream_File";
      this->file = ((char*)(std::malloc(std::strlen(filePath))));
      this->file = std::strcpy(this->file, filePath); 
    }
  template <class CharacterType> typename OutStream<CharacterType>::_string OutStream<CharacterType>::content() 
    { 
      if (!(std::strcmp(this->type, "OutStream_String"))) return ((OutStream<CharacterType>::_ostream_string*)(this->main))->str(); 
      return *(new OutStream<CharacterType>::_string);
    }
  template <class CharacterType> typename OutStream<CharacterType>::_string OutStream<CharacterType>::infomation() 
    { 
      OutStream<CharacterType>::_ostream_string stringstream;
      stringstream << this->type << ":\"" << this->file << "\"";
      return stringstream.str();
      // OutStream<CharacterType>::_string info(this->type);
      // info += ":\"";
      // info += this->file;
      // info += "\"";
      // return info;
      // return OutStream<CharacterType>::_string(this->type).append(":\"").append(this->file).append("\"");
    }
  template <class CharacterType> typename OutStream<CharacterType>::_ostream_console& OutStream<CharacterType>::to_ostream_console()
    { return (*(this->main)); }
  template <class CharacterType> typename OutStream<CharacterType>::_ostream_file   & OutStream<CharacterType>::to_ostream_file   ()
    { return (*((OutStream<CharacterType>::_ostream_file*)(this->main))); }
  template <class CharacterType> typename OutStream<CharacterType>::_ostream_string & OutStream<CharacterType>::to_ostream_string ()
    { return (*((OutStream<CharacterType>::_ostream_string*)(this->main))); }
  template <class CharacterType> typename OutStream<CharacterType>::_ostream_console& OutStream<CharacterType>::operator()() 
    { return this->to_ostream_console(); }
  template <class CharacterType> OutStream<CharacterType>::~OutStream() 
    {
      if (!(std::strcmp(this->type, "OutStream_String")))
        delete this->main;
      if (!(std::strcmp(this->type, "OutStream_File")))
        ((OutStream<CharacterType>::_ostream_file*)(this->main))->close(), delete this->main;
    }

  
  OutStream<char> std_out(std::cout);
  OutStream<char> std_log(std::clog);
  OutStream<char> std_err(std::cerr);
  OutStream<wchar_t> std_wout(std::wcout);
  OutStream<wchar_t> std_wlog(std::wclog);
  OutStream<wchar_t> std_werr(std::wcerr);
#endif //OutStream_cpp
