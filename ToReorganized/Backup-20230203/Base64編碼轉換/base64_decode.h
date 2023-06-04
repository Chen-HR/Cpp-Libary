#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bits.h"

#ifndef base64_h
  #include "base64.h"
#endif
#ifndef base64_decode_h
  #define base64_decode_h
  #ifndef base64_decode_unit_h
    #include "base64_decode_unit.h"
  #endif
  _Base64_Buffer base64_decode_string(char* destination, char* source)
    {
      #ifdef base64_decode_string_verbose
        printf("base64_decode_string: \n");
        printf("  { \n");
        printf("    entry: \n");
        printf("      {\n");
        printf("        source.string: \"%s\"\n", source);
        printf("        destination.string: \"%s\"\n", destination);
        printf("      }\n");
        printf("    calc.log: \n");
        printf("      {\n");
      #endif 
      size_t unit_number = ((int)(ceil(((double)(strlen(source)))/Base64Unit_Base64Length)));
      #ifdef base64_decode_string_verbose
        printf("        unit_number: %d\n", unit_number);
        printf("        source.length: %d as %d\n", strlen(source), unit_number*Base64Unit_Base64Length);
      #endif 
      char* new_source      = (char*)(malloc((CharByte*unit_number*Base64Unit_Base64Length)+1));
      new_source = strcpy(new_source, source);
      for (size_t index = strlen(source); index <= (CharByte*unit_number*Base64Unit_Base64Length); index++) *(new_source+index) = '\0';
      #ifdef base64_decode_string_verbose
        printf("        destination.length: %d add %d\n", strlen(destination), unit_number*Base64Unit_AsciiLength);
      #endif 
      char* new_destination = (char*)(malloc((CharByte*(strlen(destination)+(unit_number*Base64Unit_AsciiLength)))+1));
      new_destination = strcpy(new_destination, destination);
      for (size_t index = strlen(destination); index <= (CharByte*(strlen(destination)+(unit_number*Base64Unit_AsciiLength))); index++) *(new_destination+index) = '\0';
      #ifdef base64_decode_string_verbose
        printf("      }\n");
      #endif 
      _Base64_Buffer Base64_Buffer;
      Base64_Buffer.AsciiText ="";
      Base64_Buffer.Base64Text="";
      Base64_Buffer.AsciiUnit ="";
      Base64_Buffer.Base64Unit="";
      Base64_Buffer.Base64Unit_Code="";
      for (size_t index = 0; index < unit_number; index++)
        Base64_Buffer = base64_decode_string_unit(new_destination, new_source);
      source = new_source;
      destination = new_destination;
      // AsciiText = strcpy(AsciiText, destination);
      // Base64Text = strcpy(Base64Text, source);
      #ifdef base64_decode_string_verbose
        printf("    exit: \n");
        printf("      {\n");
        printf("        source.string: \"%s\"\n", source);
        printf("        destination.string: \"%s\"\n", destination);
        printf("      }\n");
        printf("  }\n");
      #endif 
      return Base64_Buffer;
    }
  // char* base64_decode_string(char* destination, char* source) // 232301110300
  //   {
  //     #ifdef base64_decode_string_verbose
  //       printf("base64_decode_string: \n");
  //       printf("  { \n");
  //       printf("    entry: \n");
  //       printf("      {\n");
  //       printf("        source.string: \"%s\"\n", source);
  //       printf("        destination.string: \"%s\"\n", destination);
  //       printf("      }\n");
  //       printf("    calc.log: \n");
  //       printf("      {\n");
  //     #endif 
  //     size_t unit_number = ((int)(ceil(((double)(strlen(source)))/Base64Unit_Base64Length)));
  //     #ifdef base64_decode_string_verbose
  //       printf("        unit_number: %d\n", unit_number);
  //       printf("        source.length: %d as %d\n", strlen(source), unit_number*Base64Unit_Base64Length);
  //     #endif 
  //     char* new_source=(char*)(malloc((CharByte*Base64Unit_NumberLimit*Base64Unit_AsciiLength)+1));
  //     // char* new_source      = (char*)(malloc((CharByte*unit_number*Base64Unit_Base64Length)+1));
  //     new_source = strcpy(new_source, source);
  //     for (size_t index = strlen(source); index <= (CharByte*unit_number*Base64Unit_Base64Length); index++) *(new_source+index) = '\0';
  //     #ifdef base64_decode_string_verbose
  //       printf("        destination.length: %d add %d\n", strlen(destination), unit_number*Base64Unit_AsciiLength);
  //     #endif 
  //     char* new_destination=(char*)(malloc((CharByte*Base64Unit_NumberLimit*Base64Unit_Base64Length)+1));
  //     // char* new_destination = (char*)(malloc((CharByte*(strlen(destination)+(unit_number*Base64Unit_AsciiLength)))+1));
  //     new_destination = strcpy(new_destination, destination);
  //     for (size_t index = strlen(destination); index <= (CharByte*(strlen(destination)+(unit_number*Base64Unit_AsciiLength))); index++) *(new_destination+index) = '\0';
  //     #ifdef base64_decode_string_verbose
  //       printf("      }\n");
  //     #endif 
  //     for (size_t index = 0; index < unit_number; index++)
  //       base64_decode_string_unit(new_destination, new_source);
  //     source = strcpy(source, new_source);
  //     destination = strcpy(destination, new_destination);
  //     free((void*)(new_source));
  //     free((void*)(new_destination));
  //     #ifdef base64_decode_string_verbose
  //       printf("    exit: \n");
  //       printf("      {\n");
  //       printf("        source.string: \"%s\"\n", source);
  //       printf("        destination.string: \"%s\"\n", destination);
  //       printf("      }\n");
  //       printf("  }\n");
  //     #endif 
  //     return destination;
  //   }
  // char* base64_decode_string(char* destination, char* source) // 202301110200
  //   {
  //     #ifdef base64_decode_string_verbose
  //       printf("base64_decode_string: \n");
  //       printf("  { \n");
  //       printf("    entry: \n");
  //       printf("      {\n");
  //       printf("        source.string: \"%s\"\n", source);
  //       printf("        destination.string: \"%s\"\n", destination);
  //       printf("      }\n");
  //       printf("    calc.log: \n");
  //       printf("      {\n");
  //     #endif 
  //     size_t unit_number = ((int)(ceil(((double)(strlen(source)))/Base64Unit_Base64Length)));
  //     #ifdef base64_decode_string_verbose
  //       printf("        unit_number: %d\n", unit_number);
  //       printf("        source.length: %d as %d\n", strlen(source), unit_number*Base64Unit_Base64Length);
  //     #endif 
  //     char* new_source      = (char*)(malloc((CharByte*unit_number*Base64Unit_Base64Length)+1));
  //     new_source = strcpy(new_source, source);
  //     for (size_t index = strlen(source); index <= (CharByte*unit_number*Base64Unit_Base64Length); index++) *(new_source+index) = '\0';
  //     #ifdef base64_decode_string_verbose
  //       printf("        destination.length: %d add %d\n", strlen(destination), unit_number*Base64Unit_AsciiLength);
  //     #endif 
  //     char* new_destination = (char*)(malloc((CharByte*(strlen(destination)+(unit_number*Base64Unit_AsciiLength)))+1));
  //     new_destination = strcpy(new_destination, destination);
  //     for (size_t index = strlen(destination); index <= (CharByte*(strlen(destination)+(unit_number*Base64Unit_AsciiLength))); index++) *(new_destination+index) = '\0';
  //     #ifdef base64_decode_string_verbose
  //       printf("      }\n");
  //     #endif 
  //     for (size_t index = 0; index < unit_number; index++)
  //       new_destination = base64_decode_string_unit(new_destination, new_source);
  //     source = new_source;
  //     destination = new_destination;
  //     #ifdef base64_decode_string_verbose
  //       printf("    exit: \n");
  //       printf("      {\n");
  //       printf("        source.string: \"%s\"\n", source);
  //       printf("        destination.string: \"%s\"\n", destination);
  //       printf("      }\n");
  //       printf("  }\n");
  //     #endif 
  //     return destination;
  //   }
#endif