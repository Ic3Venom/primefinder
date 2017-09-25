#include <stdio.h>
#include <stdlib.h>

int main()
{
    long i, max, buffer;
    short br = 0;
    FILE *fPrime = fopen("primelistc.bin", "wb+");

    printf("Finding the primes between 2 and what number? ");
    scanf("%li", &max);

    for(i = 3; i <= max; i+= 2)
    {
        fseek(fPrime, 0, SEEK_SET);

        while( 1 )
        {
            fread(&buffer, sizeof(long), 1, fPrime);

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
            printf("\n%li", buffer);
            fwrite(&buffer, sizeof(long), 1, fPrime);
        }

    }

    fclose(fPrime);
    return 0;
}
