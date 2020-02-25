/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */

//#define NUM 30   /* number of strings */
#define NUM 5

#define LEN 1200  /* max length of each string */

void swap(char a[], char b[]){

  char temp_str[strlen(a)];

  for(int i = 0; i < strlen(a); i++){
    temp_str[i] = a[i];
  }

  for(int i = 0; i <= strlen(b); i++){

    if(i == strlen(b)){
      a[i] = '\0';
    } else {
      a[i] = b[i];     
    }
  }
  for(int i = 0; i <= strlen(temp_str); i++){
    if(i == strlen(temp_str)){
      b[i] = '\0';
    } else {
      b[i] = temp_str[i];
    } 
  }
}

int main()
{
  char Strings[NUM][LEN];

  for(int k = 0; k < NUM; k++){     
    fgets(Strings[k],LEN,stdin);
  }

  puts("\nHere are the strings in the order you entered:");
  for(int i = 0; i < NUM; i++){
    for(int l = 0; l < strlen(Strings[i]); l++){
      printf("%c",Strings[i][l]);
    }
  }

  int sorted = 0;

  while(!sorted){
    sorted = 1; 
    for(int i = 0; i < NUM-1; i++){
      for(int j = 0; j < strlen(Strings[i]) && strlen(Strings[i+1]) != j; j++){
        if(Strings[i][j] < Strings[i+1][j]){
          break;
        } else if(Strings[i][j] > Strings[i+1][j]){
          swap(Strings[i],Strings[i+1]);
          sorted = 0;
          break;
        }
      }
    }
  }
  
  puts("\nIn alphabetical order, the strings are:");     
  for(int i = 0; i < NUM; i++){

    printf("%s",Strings[i]);
  }


}
