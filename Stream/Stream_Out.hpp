#include <ostream>

#ifndef Stream_Out_hpp
  #define Stream_Out_hpp
  namespace Stream_Out
    {
      template <typename CharacterType> class Std_OutStream
        {
          private:
          protected:
          public:
            
            using _ostream_console = std::basic_ostream<CharacterType, std::char_traits<CharacterType>>;
            using _ostream_file    = std::basic_ofstream<CharacterType, std::char_traits<CharacterType>>;
            using _ostream_string  = std::basic_ostringstream<CharacterType, std::char_traits<CharacterType>, std::allocator<CharacterType>>;
            
            std::basic_ostream<CharacterType, std::char_traits<CharacterType>>& main;
            const char* file;
            Std_OutStream();// std::ostringstream
            Std_OutStream(_ostream_console& );
            Std_OutStream(const char*);// std::ofstream
        };
      
    }
#endif //Stream_Out_hpp
#ifndef Stream_Out_cpp
  #include "Stream_Out.cpp"
#endif //Stream_Out_cpp