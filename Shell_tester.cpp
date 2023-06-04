
#include "Shell.hpp"

int main()
  {
    shell.execute("g++ --version");
    cmd.execute("ver");
    powershell.execute("$PSVersionTable ; Write-Host \"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\" ; hostname ;");
  }