#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define base64_encode_character_verbose
// #define base64_encode_string_unit_coder_verbose
// #define base64_encode_string_unit_verbose
// #define base64_encode_string_verbose
#include "base64.h"
// #define Base64Unit_NumberLimit  128
// #define Base64Unit_AsciiLength  3
// #define Base64Unit_Base64Length 4
int main(int argc, char const *argv[])
  {
    char* source=(char*)(malloc(CharByte*Base64Unit_NumberLimit*Base64Unit_AsciiLength));
    char* destination=(char*)(malloc((CharByte*Base64Unit_NumberLimit*Base64Unit_Base64Length)+1)); 
    for (size_t index = 0; index <= (CharByte*Base64Unit_NumberLimit*Base64Unit_Base64Length); index++) *(destination+index)='\0';
    printf("string.encode(Ascii ): "); scanf("%s", source);
    printf("string.encode(Base64): %s\n", base64_encode_string(destination, source));
    printf("\n"); return 0;
  }