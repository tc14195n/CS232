/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h>

//#define NUM 30   /* number of strings */
#define NUM 5

//#define LEN 1200  /* max length of each string */

void swap(char **a, char **b){
  char* a_addr = *a;
  *a = *b;
  *b = a_addr;
}

int main()
{
  char *Strings[NUM];

  for(int k = 0; k < NUM; k++){
    char c;
    int str_size = 0;
    Strings[k] = (char*)malloc(sizeof(char));
     c = getchar();
    while(c != '\n'){
      char *a = (char *)realloc(Strings[k],(sizeof(char)*(str_size+1)));
      Strings[k] = a;
      Strings[k][str_size] = c;
      str_size++;
      c = getchar();
    } 
  }

  puts("\nHere are the strings in the order you entered:");
  for(int i = 0; i < NUM; i++){
    printf("%s\n",Strings[i]);
  }

  int sorted = 0;

  while(!sorted){
    sorted = 1; 
    for(int i = 0; i < NUM-1; i++){
      for(int j = 0; j < strlen(Strings[i]) && strlen(Strings[i+1]) != j; j++){
        if(Strings[i][j] < Strings[i+1][j]){
          break;
        } else if(Strings[i][j] > Strings[i+1][j]){
          swap(&Strings[i],&Strings[i+1]);
          sorted = 0;
          break;
        }
      }
    }
  }
  
  puts("\nIn alphabetical order, the strings are:");     
  for(int i = 0; i < NUM; i++){
    printf("%s\n",Strings[i]);
  }


}
