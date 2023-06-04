#include <iostream> // std::ostream

#include <string>

#ifndef Log_hpp
  #define Log_hpp
  namespace Log
    {
      const char* Format = "%Y/%m/%d %H:%M:%S";
      size_t LableLength = 16;

      std::string Time() ;

      template <typename msgType> inline void stream(std::ostream&, const char*, msgType);
      template <typename msgType> inline void out(const char*, msgType);
      template <typename msgType> inline void log(const char*, msgType);
      template <typename msgType> inline void err(const char*, msgType);

      template <typename valueType> inline void stream_data_filePosition(std::ostream&, const char*, const char*, valueType);
      template <typename valueType> inline void out_data_filePosition(const char*, const char*, valueType);
      template <typename valueType> inline void log_data_filePosition(const char*, const char*, valueType);
      template <typename valueType> inline void err_data_filePosition(const char*, const char*, valueType);

      #define Log_stream_filePosition(stream, lable) Log::stream_data_filePosition(stream, lable, __FILE__, __LINE__)
      #define Log_out_filePosition(lable) Log::out_data_filePosition(lable, __FILE__, __LINE__)
      #define Log_log_filePosition(lable) Log::log_data_filePosition(lable, __FILE__, __LINE__)
      #define Log_err_filePosition(lable) Log::err_data_filePosition(lable, __FILE__, __LINE__)
      
      template <typename valueType> inline void stream_data(std::ostream&, const char*, const char*, valueType);
      template <typename valueType> inline void out_data(const char*, const char*, valueType);
      template <typename valueType> inline void log_data(const char*, const char*, valueType);
      template <typename valueType> inline void err_data(const char*, const char*, valueType);
      template <typename valueType, std::streamsize width=0, std::streamsize precision=4, char fill=' ', int base=10> inline void stream_data_number(std::ostream&, const char*, const char*, valueType);
      template <typename valueType, std::streamsize width=0, std::streamsize precision=4, char fill=' ', int base=10> inline void out_data_number                  (const char*, const char*, valueType);
      template <typename valueType, std::streamsize width=0, std::streamsize precision=4, char fill=' ', int base=10> inline void log_data_number                  (const char*, const char*, valueType);
      template <typename valueType, std::streamsize width=0, std::streamsize precision=4, char fill=' ', int base=10> inline void err_data_number                  (const char*, const char*, valueType);
      template <typename valueType, std::streamsize width=0, char fill=' '> inline void stream_data_string(std::ostream&, const char*, const char*, valueType);
      template <typename valueType, std::streamsize width=0, char fill=' '> inline void out_data_string                  (const char*, const char*, valueType);
      template <typename valueType, std::streamsize width=0, char fill=' '> inline void log_data_string                  (const char*, const char*, valueType);
      template <typename valueType, std::streamsize width=0, char fill=' '> inline void err_data_string                  (const char*, const char*, valueType);
      template <typename valueType, std::streamsize width=0, char fill=' '> inline void stream_data_boolean(std::ostream&, const char*, const char*, valueType);
      template <typename valueType, std::streamsize width=0, char fill=' '> inline void out_data_boolean                  (const char*, const char*, valueType);
      template <typename valueType, std::streamsize width=0, char fill=' '> inline void log_data_boolean                  (const char*, const char*, valueType);
      template <typename valueType, std::streamsize width=0, char fill=' '> inline void err_data_boolean                  (const char*, const char*, valueType);
    }
#endif //Log_hpp
#ifndef Log_cpp
  #include "Log.cpp"
#endif //Log_cpp