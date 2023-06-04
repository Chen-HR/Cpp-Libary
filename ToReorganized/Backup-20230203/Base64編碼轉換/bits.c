#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bits.h"
int main(int argc, char const *argv[])
  {
    char* source=(char*)(malloc((sizeof(char))*128));
    char* destination=(char*)(malloc(((sizeof(char))*128)+1)); 
    printf("source: "); scanf("%s", source);
    printf("source.length: %d\n", strlen(source));
    // printf("%d\n", ((((sizeof(char))*8)*1)+1));
    // for (size_t bit = 0; bit <= (((sizeof(char))*128)+1); bit++) *(destination+bit)='\0'; for (size_t index = 0; index < strlen(source); index++) printf("%c: %s\n", *(source+index), char_bits(destination, source+index, 1));
    for (size_t bit = 0; bit <= (((sizeof(char))*128)+1); bit++) *(destination+bit)='\0'; for (size_t index = 0; index < strlen(source); index++) printf("%c: %s\n", *(source+index), get_char_bits(source+index, 1));
    printf("\n"); return 0;
  }