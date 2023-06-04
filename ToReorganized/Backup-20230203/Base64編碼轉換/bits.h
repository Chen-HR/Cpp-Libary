#include <stdlib.h>
#include <string.h>

#ifndef bits_h
  #define bits_h
  // #define byte unsigned char
  
  // #ifndef bits_def_h
  //   #include "bits_def.h"
  // #endif 
  /** @brief Number of Bit of Byte */
  #define ByteBit 8
  /** @brief Number of Type's Byte */
  #define ByteNumber(type) sizeof(type)
  /** @brief Number of Character's Byte */
  #define CharByte (ByteNumber(char))

  /**
   * @brief Get the char bits string
   * 
   * @param destination bits string 
   * @param source      source string 
   * @param parseLength parse character length
   * @return char* destination
   */
  char* char_bits(char* destination, char* source, size_t parseLength)
    {
      char* byte_buffer = (char*)(malloc((CharByte*ByteBit)+1)); *(byte_buffer+(CharByte*ByteBit))='\0';
      for (size_t index = 0; index < parseLength; index++)
        {
          for (size_t bit = 0; bit < (CharByte*ByteBit); bit++)
            *(byte_buffer+bit) = (((((int)(*(source+index)))&(1<<((sizeof(char)*ByteBit)-bit-1)))==0)?'0':'1');
          destination = (index!=0)?strcat(destination, byte_buffer):strcpy(destination, byte_buffer);
        }
      free((void*)(byte_buffer));
      return destination;
    }
  /**
   * @brief Get char bits string
   * @ref char* char_bits(char* destination, char* source, size_t parseLength)
   * 
   * @param sourceString source string 
   * @param parseLength  parse character length
   * @return char* bitsString
   */
  char* get_char_bits(char* sourceString, size_t parseLength)
    {
      char* bitsString = (char*)(malloc(((CharByte*ByteBit)*parseLength)+1)); *(bitsString) = '\0';
      return char_bits(bitsString, sourceString, parseLength);
    }
#endif

