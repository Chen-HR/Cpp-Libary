#include <iostream> // std::ostream
#include <sstream> // std::stringstream

#include <iomanip>

#include <string>

#include <ctime>
#include <chrono>

#ifndef Log_hpp
  #include "Log.hpp"
#endif //Log_hpp
#ifndef Log_cpp
  #define Log_cpp
  std::string Log::Time() 
    {
      std::chrono::system_clock::time_point current = std::chrono::system_clock::now();
      long long current_ms = std::chrono::duration_cast<std::chrono::milliseconds>(current.time_since_epoch()).count()%1000;
      std::time_t current_datetime = std::chrono::system_clock::to_time_t(current);
      std::tm current_datetime_struct = *std::localtime(&current_datetime);
      std::stringstream result_stringstream;
      result_stringstream << std::put_time(&current_datetime_struct, Format) << "." << std::setw(3) << std::setfill('0') << current_ms;
      return result_stringstream.str();
    }

  template <typename msgType> void Log::stream(std::ostream& stream, const char* lable, msgType massage)
    { stream << Log::Time() << " [" << std::setw(Log::LableLength) << std::setfill(' ') << lable << "] " << massage << std::endl; }
  template <typename msgType> inline void Log::out(const char* lable, msgType massage) { stream(std::cout, lable, massage); }
  template <typename msgType> inline void Log::log(const char* lable, msgType massage) { stream(std::clog, lable, massage); }
  template <typename msgType> inline void Log::err(const char* lable, msgType massage) { stream(std::cerr, lable, massage); }

  template <typename valueType> void Log::stream_data_filePosition(std::ostream& stream, const char* lable, const char* name, valueType value)
    { stream << Log::Time() << " [" << std::setw(Log::LableLength) << std::setfill(' ') << lable << "] " << name << ":" << value << std::endl; }
  template <typename valueType> inline void Log::out_data_filePosition(const char* lable, const char* name, valueType value) { stream_data(std::cout, lable, name, value); }
  template <typename valueType> inline void Log::log_data_filePosition(const char* lable, const char* name, valueType value) { stream_data(std::clog, lable, name, value); }
  template <typename valueType> inline void Log::err_data_filePosition(const char* lable, const char* name, valueType value) { stream_data(std::cerr, lable, name, value); }

  template <typename valueType> void Log::stream_data(std::ostream& stream, const char* lable, const char* name, valueType value)
    { stream << Log::Time() << " [" << std::setw(Log::LableLength) << std::setfill(' ') << lable << "] " << name << ": " << value << std::endl; }
  template <typename valueType> inline void Log::out_data(const char* lable, const char* name, valueType value) { stream_data(std::cout, lable, name, value); }
  template <typename valueType> inline void Log::log_data(const char* lable, const char* name, valueType value) { stream_data(std::clog, lable, name, value); }
  template <typename valueType> inline void Log::err_data(const char* lable, const char* name, valueType value) { stream_data(std::cerr, lable, name, value); }

  template <typename valueType, std::streamsize width=0, std::streamsize precision=4, char fill=' ', int base=10> inline void Log::stream_data_number(std::ostream& stream, const char* lable, const char* name, valueType value)
    { stream << Log::Time() << " [" << std::setw(Log::LableLength) << std::setfill(' ') << lable << "] " << name << ": " << std::setw(width) << std::setprecision(precision) << std::setfill(fill) << std::setbase(base) << value << std::setbase(10) << std::endl; }
  template <typename valueType, std::streamsize width=0, std::streamsize precision=4, char fill=' ', int base=10> inline void Log::out_data_number(const char* lable, const char* name, valueType value) { stream_data_number<valueType, width, precision, fill, base>(std::cout, lable, name, value); }
  template <typename valueType, std::streamsize width=0, std::streamsize precision=4, char fill=' ', int base=10> inline void Log::log_data_number(const char* lable, const char* name, valueType value) { stream_data_number<valueType, width, precision, fill, base>(std::clog, lable, name, value); }
  template <typename valueType, std::streamsize width=0, std::streamsize precision=4, char fill=' ', int base=10> inline void Log::err_data_number(const char* lable, const char* name, valueType value) { stream_data_number<valueType, width, precision, fill, base>(std::cerr, lable, name, value); }

  template <typename valueType, std::streamsize width=0, char fill=' '> inline void Log::stream_data_string(std::ostream& stream, const char* lable, const char* name, valueType value)
    { stream << Log::Time() << " [" << std::setw(Log::LableLength) << std::setfill(' ') << lable << "] " << name << ": " << std::setw(width) << std::setfill(fill) << value << std::endl; }
  template <typename valueType, std::streamsize width=0, char fill=' '> inline void Log::out_data_string(const char* lable, const char* name, valueType value) { stream_data_string<valueType, width, fill>(std::cout, lable, name, value); }
  template <typename valueType, std::streamsize width=0, char fill=' '> inline void Log::log_data_string(const char* lable, const char* name, valueType value) { stream_data_string<valueType, width, fill>(std::clog, lable, name, value); }
  template <typename valueType, std::streamsize width=0, char fill=' '> inline void Log::err_data_string(const char* lable, const char* name, valueType value) { stream_data_string<valueType, width, fill>(std::cerr, lable, name, value); }

  template <typename valueType, std::streamsize width=0, char fill=' '> inline void Log::stream_data_boolean(std::ostream& stream, const char* lable, const char* name, valueType value)
    { stream << Log::Time() << " [" << std::setw(Log::LableLength) << std::setfill(' ') << lable << "] " << name << ": " << std::setw(width) << std::boolalpha << value << std::endl; }
  template <typename valueType, std::streamsize width=0, char fill=' '> inline void Log::out_data_boolean(const char* lable, const char* name, valueType value) { stream_data_boolean<valueType, width, fill>(std::cout, lable, name, value); }
  template <typename valueType, std::streamsize width=0, char fill=' '> inline void Log::log_data_boolean(const char* lable, const char* name, valueType value) { stream_data_boolean<valueType, width, fill>(std::clog, lable, name, value); }
  template <typename valueType, std::streamsize width=0, char fill=' '> inline void Log::err_data_boolean(const char* lable, const char* name, valueType value) { stream_data_boolean<valueType, width, fill>(std::cerr, lable, name, value); }
#endif //Log_cpp