#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long i, max, buffer;
    short br = 0;
    FILE *fPrime = fopen("primelistc.bin", "wb+");

    printf("Finding the primes between 2 and what number? ");
    scanf("%llu", &max);

    buffer = 2;
    fwrite(&buffer, sizeof(buffer), 1, fPrime);
    exit(0);

    for(i = 3; i <= max; i+= 2)
    {
        fseek(fPrime, 0, SEEK_SET);

        while( 1 )
        {
            fread((void*)(&buffer), sizeof(buffer), 1, fPrime);
            printf("%llu", buffer);
            if(feof(fPrime))
            {
                break;
            }
            if(i % buffer == 0)
            {
                br = 1;
                break;
            }
        }
        if(!br)
        {
            printf("\n%llu", buffer);
            fwrite(&buffer, sizeof(long), 1, fPrime);
        }

        br = 0;

    }

    fclose(fPrime);
    return 0;
}
