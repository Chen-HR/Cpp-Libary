#include <cvirte.h>
#include <userint.h>
#include "Base64½s½XÂà´«.h"

static int panelHandle;

int __stdcall WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
  {
    if (InitCVIRTE (hInstance, 0, 0) == 0)
      return -1;
    if ((panelHandle = LoadPanel (0, "Base64½s½XÂà´«.uir", PANEL)) < 0)
      return -1;
    DisplayPanel (panelHandle);
    RunUserInterface ();
    DiscardPanel (panelHandle);
    return 0;
  }

int CVICALLBACK Command_Quit (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
  {
    switch (event)
      {
        case EVENT_COMMIT:
          {
            QuitUserInterface (0);
          }break;
      }
    return 0;
  }

#include "base64.h"

static int Control_PlainText_Full             = PANEL_ORIGINALSTR;
static int Control_PlainText_Unit_List_Char[] = {PANEL_FIRSTASCII, PANEL_SECONDASCII, PANEL_THIRDASCII};
static int Control_PlainText_Unit_List_Code[] = {PANEL_ORIGINALCODE_1, PANEL_ORIGINALCODE_2, PANEL_ORIGINALCODE_3};
static int Control_CiperText_Full             = PANEL_BASE64STR;
static int Control_CiperText_Unit_List_Char[] = {PANEL_FIRST64, PANEL_SECOND64, PANEL_THIRD64, PANEL_FORTH64};
static int Control_CiperText_Unit_List_Code[] = {PANEL_BASE64CODE_1, PANEL_BASE64CODE_2, PANEL_BASE64CODE_3, PANEL_BASE64CODE_4};
void Set_PanelControl ( int Panel, 
    int ControlPlainTextUnitListChar[], 
    int ControlPlainTextUnitListCode[], 
    int ControlCiperTextUnitListChar[], 
    int ControlCiperTextUnitListCode[], 
    char* PlainUnit_Char, 
    char* CiperUnit_Char, 
    char* CiperUnit_Code, 
    char* PlainText, 
    char* CiperText
  )
  {
    // Set_PanelControl_Unit(panelHandle, 
    //   Control_PlainText_Unit_List_Char, 
    //   Control_PlainText_Unit_List_Code, 
    //   Control_CiperText_Unit_List_Char, 
    //   Control_CiperText_Unit_List_Code, 
    // );
    char buffer[] = {'\0', '\0'};
    for(int i = 0; i < Base64Unit_AsciiLength; i++)
      {
        SetCtrlAttribute(Panel, ControlPlainTextUnitListChar[i], ATTR_MAX_ENTRY_CHARS, 2);
        SetCtrlVal(Panel, ControlPlainTextUnitListChar[i], strncpy(buffer, (PlainUnit_Char+i), 1));
        SetCtrlVal(Panel, ControlPlainTextUnitListCode[i], (unsigned int)(*(PlainUnit_Char+i)));
      }
    for(int i = 0; i < Base64Unit_Base64Length; i++)
      {
        SetCtrlAttribute(Panel, ControlCiperTextUnitListChar[i], ATTR_MAX_ENTRY_CHARS, 2);
        SetCtrlVal(Panel, ControlCiperTextUnitListChar[i], strncpy(buffer, (CiperUnit_Char+i), 1));
        SetCtrlVal(Panel, ControlCiperTextUnitListCode[i], (unsigned int)(*(CiperUnit_Code+i)));
      }
    SetCtrlAttribute(Panel, Control_PlainText_Full, ATTR_MAX_ENTRY_CHARS, (CharByte*Base64Unit_NumberLimit*Base64Unit_AsciiLength)+1);
    SetCtrlAttribute(Panel, Control_CiperText_Full, ATTR_MAX_ENTRY_CHARS, (CharByte*Base64Unit_NumberLimit*Base64Unit_Base64Length)+1);
    SetCtrlVal(Panel, Control_PlainText_Full, PlainText);
    SetCtrlVal(Panel, Control_CiperText_Full, CiperText);
    
    // SetCtrlVal(Panel, ControlPlainTextUnitListChar[0], (char*)(*(PlainUnit_Char+0)));
    // SetCtrlVal(Panel, ControlPlainTextUnitListChar[1], (char*)(*(PlainUnit_Char+1)));
    // SetCtrlVal(Panel, ControlPlainTextUnitListChar[2], (char*)(*(PlainUnit_Char+2)));
    // SetCtrlVal(Panel, ControlPlainTextUnitListCode[0], (unsigned int)(*(PlainUnit_Char+0)));
    // SetCtrlVal(Panel, ControlPlainTextUnitListCode[1], (unsigned int)(*(PlainUnit_Char+1)));
    // SetCtrlVal(Panel, ControlPlainTextUnitListCode[2], (unsigned int)(*(PlainUnit_Char+2)));

    // SetCtrlVal(Panel, ControlCiperTextUnitListChar[0], (char*)(*(CiperUnit_Char+0)));
    // SetCtrlVal(Panel, ControlCiperTextUnitListChar[1], (char*)(*(CiperUnit_Char+1)));
    // SetCtrlVal(Panel, ControlCiperTextUnitListChar[2], (char*)(*(CiperUnit_Char+2)));
    // SetCtrlVal(Panel, ControlCiperTextUnitListChar[3], (char*)(*(CiperUnit_Char+3)));
    // SetCtrlVal(Panel, ControlCiperTextUnitListCode[0], (unsigned int)(*(CiperUnit_Code+0)));
    // SetCtrlVal(Panel, ControlCiperTextUnitListCode[1], (unsigned int)(*(CiperUnit_Code+1)));
    // SetCtrlVal(Panel, ControlCiperTextUnitListCode[2], (unsigned int)(*(CiperUnit_Code+2)));
    // SetCtrlVal(Panel, ControlCiperTextUnitListCode[3], (unsigned int)(*(CiperUnit_Code+3)));
  }
int CVICALLBACK Encode_Unit (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
  {
    switch (event)
      {
        case EVENT_COMMIT:
          {
            char* Plaintext=(char*)(malloc((CharByte*Base64Unit_NumberLimit*Base64Unit_AsciiLength)+1));
            GetCtrlVal(panel, PANEL_ORIGINALSTR, Plaintext);
            char* Cipertext=(char*)(malloc((CharByte*Base64Unit_NumberLimit*Base64Unit_Base64Length)+1));
            GetCtrlVal(panel, PANEL_BASE64STR, Cipertext);
			if (strlen(Plaintext)==0) return 0;
            _Base64_Buffer Base64_Buffer=base64_encode_string_unit(Cipertext, Plaintext);
            Set_PanelControl(panelHandle, 
              Control_PlainText_Unit_List_Char, 
              Control_PlainText_Unit_List_Code, 
              Control_CiperText_Unit_List_Char, 
              Control_CiperText_Unit_List_Code, 
              Base64_Buffer.AsciiUnit, 
              Base64_Buffer.Base64Unit, 
              Base64_Buffer.Base64Unit_Code, 
              Base64_Buffer.AsciiText, 
              Base64_Buffer.Base64Text
            );
          }break;
      }
    return 0;
  }
int CVICALLBACK Decode_Unit (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
  {
    switch (event)
      {
        case EVENT_COMMIT:
          {
            char* Plaintext=(char*)(malloc((CharByte*Base64Unit_NumberLimit*Base64Unit_AsciiLength)+1));
            GetCtrlVal(panel, PANEL_ORIGINALSTR, Plaintext);
            char* Cipertext=(char*)(malloc((CharByte*Base64Unit_NumberLimit*Base64Unit_Base64Length)+1));
            GetCtrlVal(panel, PANEL_BASE64STR, Cipertext);
			if (strlen(Cipertext)==0) return 0;
            _Base64_Buffer Base64_Buffer=base64_decode_string_unit(Plaintext, Cipertext);
            Set_PanelControl(panelHandle, 
              Control_PlainText_Unit_List_Char, 
              Control_PlainText_Unit_List_Code, 
              Control_CiperText_Unit_List_Char, 
              Control_CiperText_Unit_List_Code, 
              Base64_Buffer.AsciiUnit, 
              Base64_Buffer.Base64Unit, 
              Base64_Buffer.Base64Unit_Code, 
              Base64_Buffer.AsciiText, 
              Base64_Buffer.Base64Text
            );
          }break;
      }
    return 0;
  }

int CVICALLBACK Encode_All (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
  {
    switch (event)
      {
        case EVENT_COMMIT:
          {
            char* Plaintext=(char*)(malloc((CharByte*Base64Unit_NumberLimit*Base64Unit_AsciiLength)+1));
            GetCtrlVal(panel, PANEL_ORIGINALSTR, Plaintext);
            char* Cipertext=(char*)(malloc((CharByte*Base64Unit_NumberLimit*Base64Unit_Base64Length)+1));
            GetCtrlVal(panel, PANEL_BASE64STR, Cipertext);
			if (strlen(Plaintext)==0) return 0;
            _Base64_Buffer Base64_Buffer=base64_encode_string(Cipertext, Plaintext);
            Set_PanelControl(panelHandle, 
              Control_PlainText_Unit_List_Char, 
              Control_PlainText_Unit_List_Code, 
              Control_CiperText_Unit_List_Char, 
              Control_CiperText_Unit_List_Code, 
              Base64_Buffer.AsciiUnit, 
              Base64_Buffer.Base64Unit, 
              Base64_Buffer.Base64Unit_Code, 
              Base64_Buffer.AsciiText, 
              Base64_Buffer.Base64Text
            );
          }break;
      }
    return 0;
  }
int CVICALLBACK Decode_All (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
  {
    switch (event)
      {
        case EVENT_COMMIT:
          {
            char* Plaintext=(char*)(malloc((CharByte*Base64Unit_NumberLimit*Base64Unit_AsciiLength)+1));
            GetCtrlVal(panel, PANEL_ORIGINALSTR, Plaintext);
            char* Cipertext=(char*)(malloc((CharByte*Base64Unit_NumberLimit*Base64Unit_Base64Length)+1));
            GetCtrlVal(panel, PANEL_BASE64STR, Cipertext);
			if (strlen(Cipertext)==0) return 0;
            _Base64_Buffer Base64_Buffer=base64_decode_string(Plaintext, Cipertext);
            Set_PanelControl(panelHandle, 
              Control_PlainText_Unit_List_Char, 
              Control_PlainText_Unit_List_Code, 
              Control_CiperText_Unit_List_Char, 
              Control_CiperText_Unit_List_Code, 
              Base64_Buffer.AsciiUnit, 
              Base64_Buffer.Base64Unit, 
              Base64_Buffer.Base64Unit_Code, 
              Base64_Buffer.AsciiText, 
              Base64_Buffer.Base64Text
            );
          }break;
      }
    return 0;
  }
