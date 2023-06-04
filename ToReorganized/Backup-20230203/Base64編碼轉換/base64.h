#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bits.h"

#ifndef base64_h
  #define base64_h
  // #ifndef base64_def_h
  //   #include "base64_def.h"
  // #endif 
  /** @brief Number of Ascii Bit */
  #define AsciiBit 8
  /** @brief Number of Base64 Bit */
  #define Base64Bit 6

  #define Base64_Dictionary_Length 64
  #define Base64Unit_NumberLimit  128
  #define Base64Unit_AsciiLength  3
  #define Base64Unit_Base64Length 4
  const char* base64_dictionary = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
  typedef struct __Base64_Buffer
    {
      char* AsciiText;
      char* AsciiUnit;
      char* Base64Text;
      char* Base64Unit;
      char* Base64Unit_Code;
    } _Base64_Buffer;
  #include "base64_encode.h"
  #include "base64_decode.h"
#endif