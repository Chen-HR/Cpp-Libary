#include <stdlib.h>
#include <string.h>
#include "bits.h"


#ifdef base64_encode_unit_verbose
  #include <stdio.h>
  #ifndef base64_encode_character_verbose
    #define base64_encode_character_verbose
  #endif
  #ifndef base64_encode_string_unit_coder_verbose
    #define base64_encode_string_unit_coder_verbose
  #endif
  #ifndef base64_encode_string_unit_verbose
    #define base64_encode_string_unit_verbose
  #endif
#endif

#ifdef base64_encode_character_verbose
  #include <stdio.h>
  #ifndef base64_encode_string_unit_coder_verbose
    #define base64_encode_string_unit_coder_verbose
  #endif
  #ifndef base64_encode_string_unit_verbose
    #define base64_encode_string_unit_verbose
  #endif
#endif
#ifdef base64_encode_string_unit_coder_verbose
  #include <stdio.h>
  #ifndef base64_encode_string_unit_verbose
    #define base64_encode_string_unit_verbose
  #endif
#endif
#ifdef base64_encode_string_unit_verbose
  #include <stdio.h>
#endif

#ifndef base64_encode_h
  #include "base64_encode.h"
#endif
#ifndef base64_encode_unit_h
  #define base64_encode_unit_h
  char base64_encode_character(char base64_code, char is_align) 
    {
      #ifdef base64_encode_character_verbose
        printf("              base64_encode_character: \n");
        printf("                {\n");
        printf("                  entry: \n");
        printf("                    {\n");
        printf("                      base64_code: %s\n", get_char_bits(&base64_code,1));
        printf("                      is_align: %d\n", is_align);
        printf("                      offset: %d\n", (base64_code&63));
        printf("                    }\n");
        printf("                }\n");
      #endif 
      if (is_align==1) return *(base64_dictionary+(base64_code&(Base64_Dictionary_Length-1)));
      return *(base64_dictionary+Base64_Dictionary_Length);
    }
  char* base64_encode_string_unit_coder(char* destination, char* source, char alignLength)
    {
      #ifdef base64_encode_string_unit_coder_verbose
        printf("    base64_encode_string_unit_coder: \n");
        printf("      {\n");
        printf("        entry: \n");
        printf("          {\n");
        printf("            alignLength: %d\n", alignLength);
        printf("          }\n");
        printf("        for-index: \n");
        printf("          [\n");
      #endif 
      for (size_t index = 0; index < Base64Unit_Base64Length; index++)
        {
          #ifdef base64_encode_string_unit_coder_verbose
            printf("            { \n");
            printf("              code: %s\n", get_char_bits((source+index),1));
            printf("              is_align: ((%2d-%2d)>0) = (%3d>0) = %d\n", (AsciiBit*alignLength), (Base64Bit*index), (int)((AsciiBit*alignLength)-(Base64Bit*index)), ((((int)((AsciiBit*alignLength)-(Base64Bit*index)))>0)?(0):(1)));
          #endif 
          *(destination+index) = base64_encode_character(*(source+index), ((((int)((AsciiBit*alignLength)-(Base64Bit*index)))>0)?(1):(0)));
          #ifdef base64_encode_string_unit_coder_verbose
            printf("              coded: %c\n", *(destination+index));
            printf("            }\n");
          #endif 
        }
      *(destination+Base64Unit_Base64Length) = '\0';
      #ifdef base64_encode_string_unit_coder_verbose
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
   * @param verbose define base64_encode_string_unit_verbose to print verbose
   * @return char* 
   */
  _Base64_Buffer base64_encode_string_unit(char* destination, char* source)
    {
      #ifdef base64_encode_string_unit_verbose
        printf("base64_encode_string_unit: \n");
        printf("  {\n");
        printf("    entry: \n");
        printf("      {\n");
        printf("        source.string: \"%s\"\n", source     );
        printf("        destination.string: \"%s\"\n", destination);
        printf("      }\n");
      #endif 
      /**  @brief ascii code, char */
      char* source_unit=(char*)(malloc(CharByte*Base64Unit_AsciiLength+1));
      for (size_t index = 0; index <= Base64Unit_AsciiLength; index++) *(source_unit+index)='\0';
      source_unit = strncpy(source_unit, source, (strlen(source)>=Base64Unit_AsciiLength)?Base64Unit_AsciiLength:strlen(source));
      #ifdef base64_encode_string_unit_verbose
        printf("    sourceUnit_infomation: \n");
        printf("      {\n");
        printf("        string: \"%s\"\n", source_unit);
        printf("        string.byte(ASCII).dec: [%03d, %03d, %03d]\n", (*(source_unit+0))&127, (*(source_unit+1))&127, (*(source_unit+2))&127);
        printf("        string.byte(ASCII).hex: [%02x, %02x, %02x]\n", (*(source_unit+0))&127, (*(source_unit+1))&127, (*(source_unit+2))&127);
        printf("        string.byte(ASCII).bin: [%s, %s, %s]\n", get_char_bits((source_unit+0),1), get_char_bits((source_unit+1),1), get_char_bits((source_unit+2),1));
        printf("      }\n");
      #endif 
      /**  @brief base64 code */
      char* destination_unit=(char*)(malloc(CharByte*Base64Unit_Base64Length));
      *(destination_unit+0) =  ((*(source_unit+0))&252)>>2;
      *(destination_unit+1) = (((*(source_unit+0))&  3)<<4)|(((*(source_unit+1))&240)>>4);
      *(destination_unit+2) = (((*(source_unit+1))& 15)<<2)|(((*(source_unit+2))&192)>>6);
      *(destination_unit+3) =  ((*(source_unit+2))& 63);
      /**  @brief base64 char */
      char* destination_unit_coded=(char*)(malloc(CharByte*Base64Unit_Base64Length+1));
      destination_unit_coded = base64_encode_string_unit_coder(destination_unit_coded, destination_unit, strlen(source_unit));
      #ifdef base64_encode_string_unit_verbose
        printf("    destinationUnit_infomation: \n");
        printf("      {\n");
        printf("        string: \"%s\"\n", destination_unit_coded);
        printf("        string.byte(Base64).dec: [%03d, %03d, %03d, %03d]\n", (*(destination_unit+0))&127, (*(destination_unit+1))&127, (*(destination_unit+2))&127, (*(destination_unit+3))&127);
        printf("        string.byte(Base64).hex: [%02x, %02x, %02x, %02x]\n", (*(destination_unit+0))&127, (*(destination_unit+1))&127, (*(destination_unit+2))&127, (*(destination_unit+3))&127);
        printf("        string.byte(Base64).bin: [%s, %s, %s, %s]\n", get_char_bits((destination_unit+0),1), get_char_bits((destination_unit+1),1), get_char_bits((destination_unit+2),1), get_char_bits((destination_unit+3),1));
        printf("      }\n");
        printf("    beforeExit: \n");
        printf("      {\n");
        printf("        source.string: \"%s\"\n", source);
        printf("        destination.string: \"%s\"\n", destination);
        printf("        source.length: %d\n", strlen(source));
        printf("        destination.length: %d\n", strlen(destination));
        printf("      }\n");
      #endif 
      if (strlen(source)>Base64Unit_AsciiLength)
        for (size_t index = 0; *(source+Base64Unit_AsciiLength+index-1)!='\0' ; index++) 
          *(source+index) = *(source+Base64Unit_AsciiLength+index);
      else *(source) = '\0';
      destination = (strlen(destination)!=0)?strcat(destination, destination_unit_coded):strcpy(destination, destination_unit_coded);
      #ifdef base64_encode_string_unit_verbose
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
      //     source_unit, 
      //     destination_unit_coded, 
      //     destination_unit
      //   );
      // #endif 
      // AsciiUnit =source_unit;
      // Base64Unit=destination_unit_coded;
      // free((void*)(source_unit));
      // free((void*)(destination_unit));
      // free((void*)(destination_unit_coded));
      _Base64_Buffer Base64_Buffer;
      Base64_Buffer.AsciiText =source;
      Base64_Buffer.Base64Text=destination;
      Base64_Buffer.AsciiUnit =source_unit;
      Base64_Buffer.Base64Unit=destination_unit_coded;
      Base64_Buffer.Base64Unit_Code=destination_unit;
      return Base64_Buffer;
    }
#endif