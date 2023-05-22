# Create this file and run at 2023/03/28(+08:00)16:49:17.2736
Copy-Item -Path "D:\Studio\Programming\.vscode" -Destination "D:\Studio\Programming\Language\CCpp\Library" -Recurse ; 
Move-Item -Path "D:\Studio\Programming\Language\CCpp\Library\.vscode\*.code-workspace" -Destination "D:\Studio\Programming\Language\CCpp\Library\.vscode\$(($Project="D:\Studio\Programming\Language\CCpp\Library").Split("\")[-1]).code-workspace" ;
