#include <stdlib.h>
#include <string.h>
#include "bits.h"


#ifdef base64_decode_unit_verbose
  #include <stdio.h>
  #ifndef base64_decode_character_verbose
    #define base64_decode_character_verbose
  #endif
  #ifndef base64_decode_string_unit_coder_verbose
    #define base64_decode_string_unit_coder_verbose 
  #endif
  #ifndef base64_decode_string_unit_verbose
    #define base64_decode_string_unit_verbose
  #endif
#endif

#ifdef base64_decode_character_verbose
  #include <stdio.h>
  #ifndef base64_decode_string_unit_coder_verbose
    #define base64_decode_string_unit_coder_verbose
  #endif
  #ifndef base64_decode_string_unit_verbose
    #define base64_decode_string_unit_verbose
  #endif
#endif
#ifdef base64_decode_string_unit_coder_verbose
  #include <stdio.h>
  #ifndef base64_decode_string_unit_verbose
    #define base64_decode_string_unit_verbose
  #endif
#endif
#ifdef base64_decode_string_unit_verbose
  #include <stdio.h>
#endif

#ifndef base64_decode_h
  #include "base64_decode.h"
#endif
#ifndef base64_decode_unit_h
  #define base64_decode_unit_h
  char base64_decode_character(char base64_char) 
    {
      #ifdef base64_decode_character_verbose
        printf("              base64_decode_character: \n");
        printf("                {\n");
        printf("                  entry: \n");
        printf("                    {\n");
        printf("                      base64_char: %s\n", get_char_bits(&base64_char,1));
        printf("                    }\n");
        printf("                }\n");
      #endif 
      for(size_t i=0; i<Base64_Dictionary_Length; i++)
        if(base64_char == *(base64_dictionary+i))
          return i;
      if(base64_char == *(base64_dictionary+Base64_Dictionary_Length))
        return 0;
      return -1;
    }

  char* base64_decode_string_unit_coder(char* destination, char* source)
    {
      #ifdef base64_decode_string_unit_coder_verbose
        printf("    base64_decode_string_unit_coder: \n");
        printf("      {\n");
        printf("        entry: \n");
        printf("          {\n");
        printf("          }\n");
        printf("        for-index: \n");
        printf("          [\n");
      #endif 
      for (size_t index = 0; index < Base64Unit_Base64Length; index++)
        {
          #ifdef base64_decode_string_unit_coder_verbose
            printf("            { \n");
            printf("              code: %s\n", get_char_bits((source+index),1));
          #endif 
          *(destination+index) = base64_decode_character(*(source+index));
          #ifdef base64_decode_string_unit_coder_verbose
            printf("              coded: %c\n", *(destination+index));
            printf("            }\n");
          #endif 
        }
      *(destination+Base64Unit_Base64Length) = '\0';
      #ifdef base64_decode_string_unit_coder_verbose
        printf("          ]\n");
        printf("      }\n");
      #endif 
      return destination; 
    }
  /**
   * @brief 
   * 
   * @param destination 
   * @param source 
   * @param verbose define base64_decode_string_unit_verbose to print verbose
   * @return char* 
   */
  _Base64_Buffer base64_decode_string_unit(char* destination, char* source)
    {
      #ifdef base64_decode_string_unit_verbose
        printf("base64_decode_string_unit: \n");
        printf("  {\n");
        printf("    entry: \n");
        printf("      {\n");
        printf("        source.string: \"%s\"\n", source     );
        printf("        destination.string: \"%s\"\n", destination);
        printf("      }\n");
      #endif 
      /**  @brief base64 char */
      char* source_unit=(char*)(malloc(CharByte*Base64Unit_Base64Length+1));
      for (size_t index = 0; index <= Base64Unit_Base64Length; index++) *(source_unit+index)='\0';
      source_unit = strncpy(source_unit, source, (strlen(source)>=Base64Unit_Base64Length)?Base64Unit_Base64Length:strlen(source));
      /**  @brief base64 code */
      char* source_unit_coded=(char*)(malloc(CharByte*Base64Unit_Base64Length+1));
      source_unit_coded = base64_decode_string_unit_coder(source_unit_coded, source_unit);
      #ifdef base64_decode_string_unit_verbose
        printf("    sourceUnit_infomation: \n");
        printf("      {\n");
        printf("        string: \"%s\"\n", source_unit);
        printf("        string.byte(ASCII).dec: [%03d, %03d, %03d, %03d]\n", (*(source_unit_coded+0))&127, (*(source_unit_coded+1))&127, (*(source_unit_coded+2))&127, (*(source_unit_coded+3))&127);
        printf("        string.byte(ASCII).hex: [%02x, %02x, %02x, %02x]\n", (*(source_unit_coded+0))&127, (*(source_unit_coded+1))&127, (*(source_unit_coded+2))&127, (*(source_unit_coded+3))&127);
        printf("        string.byte(ASCII).bin: [%s, %s, %s, %s]\n", get_char_bits((source_unit_coded+0),1), get_char_bits((source_unit_coded+1),1), get_char_bits((source_unit_coded+2),1), get_char_bits((source_unit_coded+3),1));
        printf("      }\n");
      #endif 
      /**  @brief ascii code, char */
      char* destination_unit=(char*)(malloc(CharByte*Base64Unit_AsciiLength+1));
      *(destination_unit+0) = (((*(source_unit_coded+0))&63)<<2)|(((*(source_unit_coded+1))&48)>>4);
      *(destination_unit+1) = (((*(source_unit_coded+1))&15)<<4)|(((*(source_unit_coded+2))&60)>>2);
      *(destination_unit+2) = (((*(source_unit_coded+2))& 3)<<6)|(((*(source_unit_coded+3))&63)>>0);
      *(destination_unit+3) = '\0';
      // char* destination_unit_coded=(char*)(malloc(CharByte*Base64Unit_Base64Length+1));
      // destination_unit_coded = base64_decode_string_unit_coder(destination_unit_coded, destination_unit, strlen(source_unit));
      #ifdef base64_decode_string_unit_verbose
        printf("    destinationUnit_infomation: \n");
        printf("      {\n");
        printf("        string: \"%s\"\n", destination_unit);
        printf("        string.byte(Base64).dec: [%03d, %03d, %03d]\n", (*(destination_unit+0))&127, (*(destination_unit+1))&127, (*(destination_unit+2))&127);
        printf("        string.byte(Base64).hex: [%02x, %02x, %02x]\n", (*(destination_unit+0))&127, (*(destination_unit+1))&127, (*(destination_unit+2))&127);
        printf("        string.byte(Base64).bin: [%s, %s, %s]\n", get_char_bits((destination_unit+0),1), get_char_bits((destination_unit+1),1), get_char_bits((destination_unit+2),1));
        printf("      }\n");
        printf("    beforeExit: \n");
        printf("      {\n");
        printf("        source.string: \"%s\"\n", source);
        printf("        destination.string: \"%s\"\n", destination);
        printf("        source.length: %d\n", strlen(source));
        printf("        destination.length: %d\n", strlen(destination));
        printf("      }\n");
      #endif 
      if (strlen(source)>Base64Unit_Base64Length)
        for (size_t index = 0; *(source+Base64Unit_Base64Length+index-1)!='\0' ; index++) 
          *(source+index) = *(source+Base64Unit_Base64Length+index);
      else *(source) = '\0';
      destination = (strlen(destination)!=0)?strcat(destination, destination_unit):strcpy(destination, destination_unit);
      #ifdef base64_decode_string_unit_verbose
        printf("    Exit: \n");
        printf("      {\n");
        printf("        source.string: \"%s\"\n", source);
        printf("        destination.string: \"%s\"\n", destination);
        printf("        source.length: %d\n", strlen(source));
        printf("        destination.length: %d\n", strlen(destination));
        printf("      }\n");
        printf("    exit: \n");
        printf("      {\n");
        printf("        source.string: \"%s\"\n", source     );
        printf("        destination.string: \"%s\"\n", destination);
        printf("      }\n");
        printf("  }\n");
      #endif 
      // #ifdef Set_PanelControl_Unit
      //   Set_PanelControl_Unit(panelHandle, 
      //     Control_PlainText_Unit_List_Char, 
      //     Control_PlainText_Unit_List_Code, 
      //     Control_CiperText_Unit_List_Char, 
      //     Control_CiperText_Unit_List_Code, 
      //     destination_unit, 
      //     source_unit_coded, 
      //     source_unit
      //   );
      // #endif 
      // AsciiUnit =destination_unit;
      // Base64Unit=source_unit;
      // free((void*)(source_unit));
      // free((void*)(source_unit_coded));
      // free((void*)(destination_unit));
      _Base64_Buffer Base64_Buffer;
      Base64_Buffer.AsciiText =destination;
      Base64_Buffer.Base64Text=source;
      Base64_Buffer.AsciiUnit =destination_unit;
      Base64_Buffer.Base64Unit=source_unit;
      Base64_Buffer.Base64Unit_Code=source_unit_coded;
      return Base64_Buffer;
    }
#endif