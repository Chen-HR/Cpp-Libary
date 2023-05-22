#include <cstdlib>
#include <cstring>
#include <string>
#include "Log.hpp"

#ifndef Shell_hpp
  #include "Shell.hpp"
#endif //Shell_hpp
#ifndef Shell_cpp
  #define Shell_cpp
  const char* Shell::format_path = "${path}";
  const char* Shell::format_script = "${script}";
  void Shell::set(const char* path, const char* format)
    {
      this->path   = (char*)(std::malloc(std::strlen(path  )));
      this->path   = std::strcpy(this->path  , path  );
      this->format = (char*)(std::malloc(std::strlen(format)));
      this->format = std::strcpy(this->format, format);
    }
  Shell::Shell()
    { this->set("", ""); }
  /**
   * @brief Construct a new Shell:: Shell object
   * 
   * @param path 
   * @param format key: "${path}", "${script}"
   */
  Shell::Shell(const char* path, const char* format)
    { this->set(path, format); }
  int Shell::execute(const char* script)
    {
      std::string command(this->format);
      // Log::log("format", command);
      if (command.find(Shell::format_path) != std::string::npos)
        command.replace(command.find(Shell::format_path), std::strlen(Shell::format_path), path);
      // Log::log("format", command);
      if (command.find(Shell::format_script) != std::string::npos)
        command.replace(command.find(Shell::format_script), std::strlen(Shell::format_script), script);
      Log::log("format", command);
      return std::system(command.c_str());
    }
  /**
   * @brief run script in defult shell
   * E.G. `shell.execute("ver");`
   */
  Shell shell("", "${script}");
  /**
   * @brief run script in cmd
   * shell: C:\\Windows\\System32\\cmd.exe
   * E.G. `cmd.execute("ver");`
   */
  Shell cmd("C:\\Windows\\System32\\cmd.exe", "echo ${script} | ${path}");
  /**
   * @brief run script in PowerShell
   * shell: C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe
   * E.G. `PowerShell.execute("$PSVersionTable");`
   */
  Shell powershell("C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe", "${path} -Command ${script}");
#endif //Shell_cpp