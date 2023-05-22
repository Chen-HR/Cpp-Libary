
#include "Shell.hpp"

int main()
  {
    shell.execute("ver");
    cmd.execute("ver");
    powershell.execute("$PSVersionTable ; Write-Host \"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\" ; hostname ;");
  }