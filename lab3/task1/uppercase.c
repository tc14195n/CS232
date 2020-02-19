#include <stdio.h>

int main(int argc, char *argv[]) {
/* example:
 *  char str[10090];
   int ch, n = 0;

   while ((ch = getchar()) != EOF && n < 1000) {
      str[n] = ch;
      ++n;
   }

   for (int i = 0; i < n; ++i)
      putchar(str[i]);


   return 0;

 */
	char str[10090];
	int ch, n = 0;

	while ((ch = getchar()) != EOF && n < 1000) {
		//97-122 == lowercase char
		str[n] = ch;
		n++;
		//putchar(str[n]);
		if(ch > 96 && ch < 123) {
			ch -= 32;
		}
		printf("\n%c\n",ch);
	}

    return 0;
}

