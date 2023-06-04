/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1
#define  PANEL_BASE64STR                  2       /* control type: string, callback function: (none) */
#define  PANEL_ORIGINALSTR                3       /* control type: string, callback function: (none) */
#define  PANEL_BASE64CODE_4               4       /* control type: numeric, callback function: (none) */
#define  PANEL_BASE64CODE_3               5       /* control type: numeric, callback function: (none) */
#define  PANEL_BASE64CODE_2               6       /* control type: numeric, callback function: (none) */
#define  PANEL_BASE64CODE_1               7       /* control type: numeric, callback function: (none) */
#define  PANEL_ORIGINALCODE_3             8       /* control type: numeric, callback function: (none) */
#define  PANEL_ORIGINALCODE_2             9       /* control type: numeric, callback function: (none) */
#define  PANEL_ORIGINALCODE_1             10      /* control type: numeric, callback function: (none) */
#define  PANEL_THIRDASCII                 11      /* control type: string, callback function: (none) */
#define  PANEL_SECONDASCII                12      /* control type: string, callback function: (none) */
#define  PANEL_FORTH64                    13      /* control type: string, callback function: (none) */
#define  PANEL_THIRD64                    14      /* control type: string, callback function: (none) */
#define  PANEL_SECOND64                   15      /* control type: string, callback function: (none) */
#define  PANEL_FIRST64                    16      /* control type: string, callback function: (none) */
#define  PANEL_FIRSTASCII                 17      /* control type: string, callback function: (none) */
#define  PANEL_TEXTMSG                    18      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_2                  19      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_3                  20      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_4                  21      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_5                  22      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_6                  23      /* control type: textMsg, callback function: (none) */
#define  PANEL_UNITENCODEBUTTON           24      /* control type: command, callback function: Encode_Unit */
#define  PANEL_ALLENCODEBUTTON            25      /* control type: command, callback function: Encode_All */
#define  PANEL_UNITDECODEBUTTON           26      /* control type: command, callback function: Decode_Unit */
#define  PANEL_ALLDECODEBUTTON            27      /* control type: command, callback function: Decode_All */
#define  PANEL_TEXTMSG_7                  28      /* control type: textMsg, callback function: (none) */
#define  PANEL_COMMANDQUIT                29      /* control type: command, callback function: Command_Quit */
#define  PANEL_TEXTMSG_8                  30      /* control type: textMsg, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Command_Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Decode_All(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Decode_Unit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Encode_All(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Encode_Unit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif