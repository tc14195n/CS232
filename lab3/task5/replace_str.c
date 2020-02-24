#include <stdio.h>
/* Overwrites an inputted string with 232 is awesome! if there is room.
 * * Does nothing if there is not. */

/*
Questions...
This code doesn't actually take/pass any arguments. 
Example in lab document doesn't show any parameters passed...
*/

void CS232(char* src) {
     char *srcptr, replaceptr; 
     // char *srcptr, *replaceptr;
     int srcLength = sizeof(src);
     char replacement[15] = "232 is awesome!";
     srcptr = src;
     replaceptr = *replacement;
     if (srcLength >= 15) {
         //for (int i = 0; i < 15; i++){
            *srcptr = replaceptr;
            //src[i] = replacement[i];
         //}
            
     }
}

char * replace_string(char* text) {
    CS232(text);
    return text;
    //

}

int main(int argc, char ** argv) {
    //DO I NEED TO ADD PASSED PARAMETER BELOW??
    char * ret = replace_string(argv[1]);
    //
    printf("replaced string = %s\n", ret);

    return 0;
}

/*
char * replace_string(char* text) {
    char str[15];
    CS232(str);
    //problem with this line
    //str is local variable. can't return this.
    return str;
    //

}

int main(int argc, char ** argv) {
    //DO I NEED TO ADD PASSED PARAMETER BELOW??
    char * ret = replace_string(argv[1]);
    //
    printf("replaced string = %s\n", ret);

    return 0;
}
*/
