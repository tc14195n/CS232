#include "syscall.h"
#include "stdio.h"
#define Dim 	64

int A[Dim][Dim];
int B[Dim][Dim];
int C[Dim][Dim];

int
main()
{
    int i, j, k, r;

    for (i = 0; i < Dim; i++)		/* first initialize the matrices */
	for (j = 0; j < Dim; j++) {
	     A[i][j] = i;
	     B[i][j] = j;
	     C[i][j] = 0;
	}

    for(i = 0; i < Dim; i++){
    	for(k = 0; k < Dim; k++){
    		r = A[i][k];
    		for(j=0;j < Dim; j++)
    			C[i][j] += r * B[k][j];
    	}
    }

    printf("C[%d][%d] = %d\n", Dim-1, Dim-1, C[Dim-1][Dim-1]);
    return (C[Dim-1][Dim-1]);		/* and then we're done */
}

