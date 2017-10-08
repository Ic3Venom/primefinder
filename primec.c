#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//#include <sys/time.h>

int main()
{
    unsigned long long int i, j, max, buffer, count;
    short br, wr;
    FILE *output, *fp;
    //struct timeval start, stop;

    fp = fopen("primes.bin", "wb+");
    max = 10;
    wr = 0;
    buffer = 2;
    count = 1; //2 is already included

    //gettimeofday(&start, NULL);
    fwrite((const void*)&buffer, sizeof(ULLONG_MAX), 1, fp);
    fseek(fp, 0, SEEK_SET);

    for(i = 3; i <= max; i+= 2)
    {
        double guess = 1;
        br = 0; //initialize or reset from previous loop

        {
            for(j = 0; j < 15; j++)
            {
                guess = (0.5) * (guess + ((double)i/guess));
            }
        }

        fseek(fp, 0, SEEK_SET);

        while( 1 )
        {
            fread(&buffer, sizeof(ULLONG_MAX), 1, fp);

            if(i % buffer == 0)
            {
                br = 1;
                break;
            }

            if ((double)buffer > guess || feof(fp))
            {
                break;
            }
        }

        if(br == 0)
        {
            fseek(fp, 0, SEEK_END);
            fwrite((const void*)&i, sizeof(ULLONG_MAX), 1, fp);
            count++;
        }
    }

    //gettimeofday(&stop, NULL);

    printf("Total primes from 2 to %llu: %llu", max, count);

    if( wr )
    {
        output = fopen("primes.txt", "w");
        fseek(fp, 0, SEEK_SET);
        while( count > 0 )
        {
            count--;
            fread(&buffer, sizeof(ULLONG_MAX), 1, fp);
            fprintf(output, "%llu\n", buffer);
        }
        fclose(output);
    }
    /*printf("\nTotal time: %f seconds", ((stop.tv_sec - start.tv_sec)
                                        * 1000.0f + (stop.tv_usec - start.tv_usec)
                                        / 1000.0f) /1000.0f);*/
    fclose(fp);
}
