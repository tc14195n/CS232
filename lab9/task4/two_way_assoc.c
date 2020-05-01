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
        int ind = (addr >> 2) & 3;
        int k;
        int tg = addr | 0xf;

        for(k = 0; k < 2; k++)
        {
            if(tag[ind][k] == tg)
            {
                printf("Its a Hit");
                mru[ind] = k;
                hits++;
                break;
            }
        }

        if(k == 2)
        {
            printf("Its a Miss");
            int x = (mru[ind] + 1)%2;
            tag[ind][x] = tg;
            mru[ind] = x;
        }

        for(int i = 0; i < 4; i++)
        {
            printf(" 0x%08x 0x%08x\n",tag[i][0], tag[i][1]);
        }

        for(int i = 0; i < 4; i++)
            printf("%d ", mru[i]);
        printf("\n");

	}

    printf("Hits = %d, Accesses = %d, Hit ratio = %f\n", hits, accesses, ((float)hits)/accesses);
    fclose(fp);

}
