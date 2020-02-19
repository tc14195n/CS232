#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int letter_frequency[26] = {0};
  int len, i;
  char buf[MAX_BUF];

  do {
    fgets(buf,MAX_BUF,stdin);
    len = strlen(buf);
    for(int i = 0; i < len; i++){
      if(buf[i] > 64 && buf[i] < 91){
        letter_frequency[buf[i] - 65]++;
      } else if (buf[i] > 96 && buf[i] < 123){
        letter_frequency[buf[i] - 97]++;
      }
    }
  } while (len > 1);

  printf("Distribution of letters in corpus:\n");
  for (i = 0; i < 26; i++) {
    // 'A' is ASCII code 65
    printf("%c: %d\n", 65+i, letter_frequency[i]);
  }
}
