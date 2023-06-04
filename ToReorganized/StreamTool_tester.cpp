#include <string>
#include <cstring>
#include "StreamTool.hpp"

#define CompileInformation

int main(int argc, char** argv)
  {
    StreamTool ioTool((char*)("  "), 4);
    #ifdef CompileInformation
      ioTool.putDescription("Compile Information:", ioTool.Indentation, 0, true);
      #ifdef __cplusplus
        ioTool.putDescription("C++ standard: "+std::to_string(__cplusplus), ioTool.Indentation, 1, true);
      #endif
      #ifdef __FILE__
        { char buffer[256];
          ioTool.putDescription(std::strcat(std::strcpy(buffer,"file        : "),__FILE__), ioTool.Indentation, 1, true);
        }
      #endif
      #ifdef __DATE__
        { char buffer[64];
          ioTool.putDescription(std::strcat(std::strcpy(buffer,"date        : "),__DATE__), ioTool.Indentation, 1, true);
        }
      #endif
      #ifdef __TIME__
        { char buffer[64];
          ioTool.putDescription(std::strcat(std::strcpy(buffer,"time        : "),__TIME__), ioTool.Indentation, 1, true);
        }
      #endif
    #endif
  }