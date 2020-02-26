/* Overwrites an inputted string with 232 is awesome! if there is room.
 * * Does nothing if there is not. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Overwrites an inputted string with 232 is awesome! if there is room.
 * * Does nothing if there is not. 
*/

void CS232(char* src) {
     char *srcptr, *replaceptr; 
     // char *srcptr, *replaceptr;
     int srcLength = sizeof(*src);
     printf("srcLength: %d",(int)sizeof(src));
     char replacement[15] = "232 is awesome!";
     srcptr = src;
     replaceptr = replacement;
     if (srcLength >= 15) {
         for (int i = 0; i < 15; i++)
          *srcptr++ = *replaceptr++;
     }
}

char * replace_string() {
    char str[15];
    //char* str = (char*)calloc(15,sizeof(char));
    CS232(str);
    return str;

}

int main(int argc, char ** argv) {
    char * ret = replace_string();
    printf("replaced string = %s\n", ret);
    return 0;
}
