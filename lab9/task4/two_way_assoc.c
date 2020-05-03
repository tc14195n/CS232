#include <stdio.h>

int tag[2][4];
int mru[4] = {1,1,1,1};

int main( )
{
    int addr;
    int hits, accesses;
    FILE *fp;

    fp = fopen("trace.txt", "r");
    hits = 0;
    accesses = 0;
    while(fscanf(fp, "%x", &addr) > 0)
	{
	accesses++;
        int index = (addr > 2) & 3;
        int k;
        int tg = addr | 0xf;

        for(k = 0; k < 2; k++)
        {
            if(tag[index][k] == tg)
            {
                printf(" Status: Hit ");
                mru[index] = k;
                hits++;
            }
        }

        if(k == 2)
        {
            printf(" Status: Miss ");
            int x = (mru[index] + 1)%2;
            tag[index][x] = tg;
            mru[index] = x;
        }

        for(int i = 0; i < 4; i++)
        {
            printf(" 0x%08x 0x%08x\n",tag[i][0], tag[i][1]);
        }

        for(int i = 0; i < 4; i++)
            printf("%d ", mru[i]);

	}

    printf("Hits = %d, Accesses = %d, Hit ratio = %f\n", hits, accesses, ((float)hits)/accesses);
    fclose(fp);

}

