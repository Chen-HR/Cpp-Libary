#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define base64_decode_character_verbose
// #define base64_decode_string_unit_coder_verbose
// #define base64_decode_string_unit_verbose
#include "base64.h"
// #define Base64Unit_NumberLimit  128
#define Base64Unit_AsciiLength  3
#define Base64Unit_Base64Length 4
int main(int argc, char const *argv[])
  {
    char* source=(char*)(malloc(CharByte*Base64Unit_Base64Length));
    char* destination=(char*)(malloc((CharByte*Base64Unit_AsciiLength)+1)); 
    for (size_t index = 0; index <= (CharByte*Base64Unit_AsciiLength); index++) *(destination+index)='\0';
    printf("string.decode(Base64).unit: "); scanf("%s", source);
    printf("string.decode(Ascii ).unit: %s\n", base64_decode_string_unit(destination, source).AsciiUnit);
    printf("\n"); return 0;
  }