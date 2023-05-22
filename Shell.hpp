#include <string>

#ifndef Shell_hpp
  #define Shell_hpp
  class Shell
    {
      private:
      protected:
        void set(const char*, const char*);
      public:
        static const char* format_path;
        static const char* format_script;
        char* path;
        char* format;
        Shell();
        Shell(const char*, const char*);
        int execute(const char*);
    };
#endif //Shell_hpp
#ifndef Shell_cpp
  #include "Shell.cpp"
#endif //Shell_cpp