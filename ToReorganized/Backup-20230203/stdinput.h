// https://www.itread01.com/content/1545366902.html
// https://blog.csdn.net/qq_40757240/article/details/105504524
// mouse_event : https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-mouse_event
// keybd_event : https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-keybd_event

#include <windows.h>
#include <string>

// #define KEYEVENTF_KEYDOWN 0x0000
// #define KEYEVENTF_KEYUP   0x0002

namespace STDINPUT
  {
    class MOUSE
      {
        private:
          //coordinate
          POINT point;
        public:
          //Mobile function
          inline void Move(int x,int y);
          inline void RelativeMove(int cx,int cy);
          inline void SavePos();
          inline void RestorePos();
          //Lock enable class
          inline void Lock();
          inline void Unlock();
          //Action
          inline void LBClick(unsigned long long int );
          inline void LBDown();
          inline void LBUp();
          inline void RBClick(unsigned long long int );
          inline void RBDown();
          inline void RBUp();
          inline void MBClick(unsigned long long int );
          inline void MBDown();
          inline void MBUp();
          //inline void    MBRoll(int ch);
      };
      //Move the mouse to the absolute position (X coordinate, Y coordinate)
      inline void MOUSE::Move(int x,int y)
        {
          this->point.x=x;
          this->point.y=y;
          ::SetCursorPos(x,y);
        }
      //Move the mouse to the relative position (X displacement, Y displacement)
      inline void MOUSE::RelativeMove(int cx,int cy)
        {
          ::GetCursorPos(&this->point);
          this->point.x+=cx;
          this->point.y+=cy;
          ::SetCursorPos(this->point.x,this->point.y);
        }
      //Save current location ()
      inline void MOUSE::SavePos()
        {
          ::GetCursorPos(&this->point);
        }
      //Restore mouse position ()
      inline void MOUSE::RestorePos()
        {
          ::SetCursorPos(this->point.x,this->point.y);
        }
      //Lock mouse ()
      inline void MOUSE::Lock()
        {
          POINT    pt;
          RECT    rt;
          ::GetCursorPos(&pt);
          rt.left=rt.right=pt.x;
          rt.top=rt.bottom=pt.y;
          rt.right++;
          rt.bottom++;
          ::ClipCursor(&rt);
        }
      //Unlock mouse ()
      inline void MOUSE::Unlock()
        {
          ::ClipCursor(NULL);
        }
      //Left button click ()
      inline void MOUSE::LBClick(unsigned long long int frequency=1)
        {
          this->SavePos();
          while (frequency--)
            ::mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,this->point.x,this->point.y,0,0);
        }
      //Left button down ()
      inline void MOUSE::LBDown()
        {
          this->SavePos();
          ::mouse_event(MOUSEEVENTF_LEFTDOWN,this->point.x,this->point.y,0,0);
        }
      //Left button up ()
      inline void MOUSE::LBUp()
        {
          this->SavePos();
          ::mouse_event(MOUSEEVENTF_LEFTUP,this->point.x,this->point.y,0,0);
        }
      //Right button click ()
      inline void MOUSE::RBClick(unsigned long long int frequency=1)
        {
          this->SavePos();
          while (frequency--)
            ::mouse_event(MOUSEEVENTF_RIGHTDOWN|MOUSEEVENTF_RIGHTUP,this->point.x,this->point.y,0,0);
        }
      //Right button down ()
      inline void MOUSE::RBDown()
        {
          this->SavePos();
          ::mouse_event(MOUSEEVENTF_RIGHTDOWN,this->point.x,this->point.y,0,0);
        }
      //Right button up ()
      inline void MOUSE::RBUp()
        {
          this->SavePos();
          ::mouse_event(MOUSEEVENTF_RIGHTUP,this->point.x,this->point.y,0,0);
        }
      //Middle button click ()
      inline void MOUSE::MBClick(unsigned long long int frequency=1)
        {
          this->SavePos();
          while (frequency--)
            ::mouse_event(MOUSEEVENTF_MIDDLEDOWN|MOUSEEVENTF_MIDDLEUP,this->point.x,this->point.y,0,0);
        }
      //Middle button down ()
      inline void MOUSE::MBDown()
        {
          this->SavePos();
          ::mouse_event(MOUSEEVENTF_MIDDLEDOWN,this->point.x,this->point.y,0,0);
        }
      //Middle button up ()
      inline void MOUSE::MBUp()
        {
          this->SavePos();
          ::mouse_event(MOUSEEVENTF_MIDDLEUP,this->point.x,this->point.y,0,0);
        }
    class KEYBOARD
      {
        //inline void keybd_event(BYTE bVk, BYTE bScan, DWORD dwFlags, ULONG_PTR dwExtraInfo)
        private:
        protected:
        public:
          //Parse KeyID
          static BYTE ParseKeyID(std::string);
          //Lock enable class
          //inline void CapsLock();
          //inline void NumLock();
          //inline void ScrollLock();
          //Action
          inline void Click(BYTE,unsigned long long int);
          inline void Down(BYTE);
          inline void Up(BYTE);
      };
    BYTE KEYBOARD::ParseKeyID(std::string key)
      {
        BYTE result=0;
        /*VK_LBUTTON    01 1    */ if (key=="mouse-left"    ) result=VK_LBUTTON    ;
        /*VK_RBUTTON    02 2    */ if (key=="mouse-right"   ) result=VK_RBUTTON    ;
        /*VK_CANCEL     03 3    */ if (key=="Ctrl-Break"    ) result=VK_CANCEL     ;
        /*VK_MBUTTON    04 4    */ if (key=="mouse-middle"  ) result=VK_MBUTTON    ;
        /*VK_BACK       08 8    */ if (key=="Backspace"     ) result=VK_BACK       ;
        /*VK_TAB        09 9    */ if (key=="Tab"           ) result=VK_TAB        ;
        /*VK_CLEAR      0C 12   */ if (key=="Clear"         ) result=VK_CLEAR      ;
        /*VK_RETURN     0D 13   */ if (key=="Enter"         ) result=VK_RETURN     ;
        /*VK_SHIFT      10 16   */ if (key=="Shift"         ) result=VK_SHIFT      ;
        /*VK_CONTROL    11 17   */ if (key=="Ctrl"          ) result=VK_CONTROL    ;
        /*VK_MENU       12 18   */ if (key=="Alt"           ) result=VK_MENU       ;
        /*VK_PAUSE      13 19   */ if (key=="Pause"         ) result=VK_PAUSE      ;
        /*VK_CAPITAL    14 20   */ if (key=="Caps-Lock"     ) result=VK_CAPITAL    ;
        /*VK_ESCAPE     1B 27   */ if (key=="Esc"           ) result=VK_ESCAPE     ;
        /*VK_SPACE      20 32   */ if (key=="Space"         ) result=VK_SPACE      ;
        /*VK_PRIOR      21 33   */ if (key=="Page-Up"       ) result=VK_PRIOR      ;
        /*VK_NEXT       22 34   */ if (key=="Page-Down"     ) result=VK_NEXT       ;
        /*VK_END        23 35   */ if (key=="End"           ) result=VK_END        ;
        /*VK_HOME       24 36   */ if (key=="Home"          ) result=VK_HOME       ;
        /*VK_LEFT       25 37   */ if (key=="left"          ) result=VK_LEFT       ;
        /*VK_UP         26 38   */ if (key=="up"            ) result=VK_UP         ;
        /*VK_RIGHT      27 39   */ if (key=="right"         ) result=VK_RIGHT      ;
        /*VK_DOWN       28 40   */ if (key=="down"          ) result=VK_DOWN       ;
        /*VK_SELECT     29 41   */ if (key=="Select"        ) result=VK_SELECT     ;
        /*VK_PRINT      2A 42   */ if (key=="Print"         ) result=VK_PRINT      ;
        /*VK_EXECUTE    2B 43   */ if (key=="Execute"       ) result=VK_EXECUTE    ;
        /*VK_SNAPSHOT   2C 44   */ if (key=="Print-Screen"  ) result=VK_SNAPSHOT   ;
        /*VK_INSERT     2D 45   */ if (key=="Ins"           ) result=VK_INSERT     ;
        /*VK_DELETE     2E 46   */ if (key=="Del"           ) result=VK_DELETE     ;
        /*VK_HELP       2F 47   */ if (key=="Help"          ) result=VK_HELP       ;
        //VK_0          30 48   */ if (key=="0"             ) result=VK_0          ;
        //VK_1          31 49   */ if (key=="1"             ) result=VK_1          ;
        //VK_2          32 50   */ if (key=="2"             ) result=VK_2          ;
        //VK_3          33 51   */ if (key=="3"             ) result=VK_3          ;
        //VK_4          34 52   */ if (key=="4"             ) result=VK_4          ;
        //VK_5          35 53   */ if (key=="5"             ) result=VK_5          ;
        //VK_6          36 54   */ if (key=="6"             ) result=VK_6          ;
        //VK_7          37 55   */ if (key=="7"             ) result=VK_7          ;
        //VK_8          38 56   */ if (key=="8"             ) result=VK_8          ;
        //VK_9          39 57   */ if (key=="9"             ) result=VK_9          ;
        //VK_A          41 65   */ if (key=="A"             ) result=VK_A          ;
        //VK_B          42 66   */ if (key=="B"             ) result=VK_B          ;
        //VK_C          43 67   */ if (key=="C"             ) result=VK_C          ;
        //VK_D          44 68   */ if (key=="D"             ) result=VK_D          ;
        //VK_E          45 69   */ if (key=="E"             ) result=VK_E          ;
        //VK_F          46 70   */ if (key=="F"             ) result=VK_F          ;
        //VK_G          47 71   */ if (key=="G"             ) result=VK_G          ;
        //VK_H          48 72   */ if (key=="H"             ) result=VK_H          ;
        //VK_I          49 73   */ if (key=="I"             ) result=VK_I          ;
        //VK_J          4A 74   */ if (key=="J"             ) result=VK_J          ;
        //VK_K          4B 75   */ if (key=="K"             ) result=VK_K          ;
        //VK_L          4C 76   */ if (key=="L"             ) result=VK_L          ;
        //VK_M          4D 77   */ if (key=="M"             ) result=VK_M          ;
        //VK_N          4E 78   */ if (key=="N"             ) result=VK_N          ;
        //VK_O          4F 79   */ if (key=="O"             ) result=VK_O          ;
        //VK_P          50 80   */ if (key=="P"             ) result=VK_P          ;
        //VK_Q          51 81   */ if (key=="Q"             ) result=VK_Q          ;
        //VK_R          52 82   */ if (key=="R"             ) result=VK_R          ;
        //VK_S          53 83   */ if (key=="S"             ) result=VK_S          ;
        //VK_T          54 84   */ if (key=="T"             ) result=VK_T          ;
        //VK_U          55 85   */ if (key=="U"             ) result=VK_U          ;
        //VK_V          56 86   */ if (key=="V"             ) result=VK_V          ;
        //VK_W          57 87   */ if (key=="W"             ) result=VK_W          ;
        //VK_X          58 88   */ if (key=="X"             ) result=VK_X          ;
        //VK_Y          59 89   */ if (key=="Y"             ) result=VK_Y          ;
        //VK_Z          5A 90   */ if (key=="Z"             ) result=VK_Z          ;
        /*VK_LWIN       5B 91   */ if (key=="left-Windows"  ) result=VK_LWIN       ;
        /*VK_RWIN       5C 92   */ if (key=="right-Windows" ) result=VK_RWIN       ;
        /*VK_APPS       5D 93   */ if (key=="APPS"          ) result=VK_APPS       ;
        /*VK_SLEEP      5F 95   */ if (key=="SLEEP"         ) result=VK_SLEEP      ;
        /*VK_NUMPAD0    60 96   */ if (key=="Num-0"         ) result=VK_NUMPAD0    ;
        /*VK_NUMPAD1    61 97   */ if (key=="Num-1"         ) result=VK_NUMPAD1    ;
        /*VK_NUMPAD2    62 98   */ if (key=="Num-2"         ) result=VK_NUMPAD2    ;
        /*VK_NUMPAD3    63 99   */ if (key=="Num-3"         ) result=VK_NUMPAD3    ;
        /*VK_NUMPAD4    64 100  */ if (key=="Num-4"         ) result=VK_NUMPAD4    ;
        /*VK_NUMPAD5    65 101  */ if (key=="Num-5"         ) result=VK_NUMPAD5    ;
        /*VK_NUMPAD6    66 102  */ if (key=="Num-6"         ) result=VK_NUMPAD6    ;
        /*VK_NUMPAD7    67 103  */ if (key=="Num-7"         ) result=VK_NUMPAD7    ;
        /*VK_NUMPAD8    68 104  */ if (key=="Num-8"         ) result=VK_NUMPAD8    ;
        /*VK_NUMPAD9    69 105  */ if (key=="Num-9"         ) result=VK_NUMPAD9    ;
        /*VK_MULTIPLY   6A 106  */ if (key=="*"             ) result=VK_MULTIPLY   ;
        /*VK_ADD        6B 107  */ if (key=="+"             ) result=VK_ADD        ;
        /*VK_SEPARATOR  6C 108  */ if (key=="SEPARATOR"     ) result=VK_SEPARATOR  ;
        //VK_SUBSTRACT  6D 109  */ if (key=="-"             ) result=VK_SUBSTRACT  ;
        /*VK_DECIMAL    6E 110  */ if (key=="."             ) result=VK_DECIMAL    ;
        /*VK_DIVIDE     6F 111  */ if (key=="/"             ) result=VK_DIVIDE     ;
        /*VK_F1         70 112  */ if (key=="F1"            ) result=VK_F1         ;
        /*VK_F2         71 113  */ if (key=="F2"            ) result=VK_F2         ;
        /*VK_F3         72 114  */ if (key=="F3"            ) result=VK_F3         ;
        /*VK_F4         73 115  */ if (key=="F4"            ) result=VK_F4         ;
        /*VK_F5         74 116  */ if (key=="F5"            ) result=VK_F5         ;
        /*VK_F6         75 117  */ if (key=="F6"            ) result=VK_F6         ;
        /*VK_F7         76 118  */ if (key=="F7"            ) result=VK_F7         ;
        /*VK_F8         77 119  */ if (key=="F8"            ) result=VK_F8         ;
        /*VK_F9         78 120  */ if (key=="F9"            ) result=VK_F9         ;
        /*VK_F10        79 121  */ if (key=="F10"           ) result=VK_F10        ;
        /*VK_F11        7A 122  */ if (key=="F11"           ) result=VK_F11        ;
        /*VK_F12        7B 123  */ if (key=="F12"           ) result=VK_F12        ;
        /*VK_F13        7C 124  */ if (key=="F13"           ) result=VK_F13        ;
        /*VK_F14        7D 125  */ if (key=="F14"           ) result=VK_F14        ;
        /*VK_F15        7E 126  */ if (key=="F15"           ) result=VK_F15        ;
        /*VK_F16        7F 127  */ if (key=="F16"           ) result=VK_F16        ;
        /*VK_F17        80 128  */ if (key=="F17"           ) result=VK_F17        ;
        /*VK_F18        81 129  */ if (key=="F18"           ) result=VK_F18        ;
        /*VK_F19        82 130  */ if (key=="F19"           ) result=VK_F19        ;
        /*VK_F20        83 131  */ if (key=="F20"           ) result=VK_F20        ;
        /*VK_F21        84 132  */ if (key=="F21"           ) result=VK_F21        ;
        /*VK_F22        85 133  */ if (key=="F22"           ) result=VK_F22        ;
        /*VK_F23        86 134  */ if (key=="F23"           ) result=VK_F23        ;
        /*VK_F24        87 135  */ if (key=="F24"           ) result=VK_F24        ;
        /*VK_NUMLOCK    90 144  */ if (key=="Num-Lock"      ) result=VK_NUMLOCK    ;
        /*VK_SCROLL     91 145  */ if (key=="Scroll-Lock"   ) result=VK_SCROLL     ;
        /*VK_LSHIFT     A0 160  */ if (key=="left-Shift"    ) result=VK_LSHIFT     ;
        /*VK_RSHIFT     A1 161  */ if (key=="left-Shift"    ) result=VK_RSHIFT     ;
        /*VK_LCONTROL   A2 162  */ if (key=="left-Ctrl"     ) result=VK_LCONTROL   ;
        /*VK_RCONTROL   A3 163  */ if (key=="right-Ctrl"    ) result=VK_RCONTROL   ;
        /*VK_LMENU      A4 164  */ if (key=="right-Alt"     ) result=VK_LMENU      ;
        /*VK_RMENU      A5 165  */ if (key=="right-Alt"     ) result=VK_RMENU      ;
        return result;
      }
    //Keyboard button down
    inline void KEYBOARD::Down(BYTE VK_id)
      {keybd_event(VK_id,0,KEYEVENTF_EXTENDEDKEY,0);}
    //Keyboard button up
    inline void KEYBOARD::Up(BYTE VK_id)
      {keybd_event(VK_id,0,KEYEVENTF_KEYUP      ,0);}
    //Keyboard button click
    inline void KEYBOARD::Click(BYTE VK_id,unsigned long long int frequency=1)
      {while (frequency--) Down(VK_id),Up(VK_id);}
  }
//0123456789
//8901234567
//abcdefghijklmnopqrstuvwxyz
//keyboard.Click(keyboard.ParseKeyID("Num-1"));
//78901234567890123456789012
// 056
// 048
// 048
// 046
// 106
// 102
// 105
// 102
//keyboard.Click(keyboard.ParseKeyID("Num-0"));
//keyboard.Click(keyboard.ParseKeyID("Num-5"));
//keyboard.Click(keyboard.ParseKeyID("Num-6"));
//keyboard.up(keyboard.ParseKeyID("Alt"));
//keyboard.Down(keyboard.ParseKeyID("Alt"));
//keyboard.Click(keyboard.ParseKeyID("Num-0"));
//keyboard.Click(keyboard.ParseKeyID("Num-4"));
//keyboard.Click(keyboard.ParseKeyID("Num-8"));
//keyboard.up(keyboard.ParseKeyID("Alt"));
//keyboard.Down(keyboard.ParseKeyID("Alt"));
//keyboard.Click(keyboard.ParseKeyID("Num-0"));
//keyboard.Click(keyboard.ParseKeyID("Num-4"));
//keyboard.Click(keyboard.ParseKeyID("Num-8"));
//keyboard.up(keyboard.ParseKeyID("Alt"));
//keyboard.Down(keyboard.ParseKeyID("Alt"));
//keyboard.Click(keyboard.ParseKeyID("Num-0"));
//keyboard.Click(keyboard.ParseKeyID("Num-4"));
//keyboard.Click(keyboard.ParseKeyID("Num-6"));
//keyboard.up(keyboard.ParseKeyID("Alt"));
//keyboard.Down(keyboard.ParseKeyID("Alt"));
//keyboard.Click(keyboard.ParseKeyID("Num-1"));
//keyboard.Click(keyboard.ParseKeyID("Num-0"));
//keyboard.Click(keyboard.ParseKeyID("Num-6"));
//keyboard.up(keyboard.ParseKeyID("Alt"));
//keyboard.Down(keyboard.ParseKeyID("Alt"));
//keyboard.Click(keyboard.ParseKeyID("Num-1"));
//keyboard.Click(keyboard.ParseKeyID("Num-0"));
//keyboard.Click(keyboard.ParseKeyID("Num-2"));
//keyboard.up(keyboard.ParseKeyID("Alt"));
//keyboard.Down(keyboard.ParseKeyID("Alt"));
//keyboard.Click(keyboard.ParseKeyID("Num-0"));
//keyboard.Click(keyboard.ParseKeyID("Num-5"));
//keyboard.up(keyboard.ParseKeyID("Alt"));
//keyboard.Down(keyboard.ParseKeyID("Alt"));
//keyboard.Click(keyboard.ParseKeyID("Num-1"));
//keyboard.Click(keyboard.ParseKeyID("Num-0"));
//keyboard.Click(keyboard.ParseKeyID("Num-2"));
//keyboard.up(keyboard.ParseKeyID("Alt"));