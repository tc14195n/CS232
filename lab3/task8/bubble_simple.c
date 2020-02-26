/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */

#define NUM 30   /* number of strings */

#define LEN 1200  /* max length of each string */

void swap(char a[], char b[]){

  char temp_str[strlen(a)];
  strcpy(temp_str, a);
  strcpy(a,b);
  strcpy(b,temp_str);
}

int main()
{
  char Strings[NUM][LEN];

  for(int k = 0; k < NUM; k++){     
    fgets(Strings[k],LEN,stdin);
  }

  puts("\nHere are the strings in the order you entered:");
  for(int i = 0; i < NUM; i++){
    printf("%s",Strings[i]);
  }

  int sorted = 0;

  while(!sorted){
    sorted = 1; 
    for(int i = 0; i < NUM-1; i++){
        int cmp = strcmp(Strings[i], Strings[i+1]);
        if(cmp > 0){
          swap(Strings[i],Strings[i+1]);
          sorted = 0;
        }
    }
  }
  
  puts("\nIn alphabetical order, the strings are:");     
  for(int i = 0; i < NUM; i++){
    printf("%s",Strings[i]);
  }


}
