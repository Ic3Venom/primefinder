#include <iostream>
#include <fstream>
#include <time.h>


int primes(int maxRange)
{
    std::fstream file ("primes.txt", std::fstream::in | std::fstream::out);
    std::string line;
    int amount = 0;

    if (maxRange % 2 == 0)
    {
         maxRange--;
    }

    if (file.is_open())
    {
        file << "2 \n";

        for(int i = 3; i <= maxRange +1; i += 2)
        {
            for(int j = 3; j <= i; j += 2)
            {
                if( i % j == 0 )
                {
                    goto skip;
                }
            }
            file << i << "\n";

            skip:
            continue;
        }

        file.seekg(0);
        while( std::getline(file, line) )
        {
            amount++;
        }

        file.close();
    }
    else
    {
        std::cout<<"Something went wrong when opening 'primes.bin'! Exiting program.";
        std::exit(1);
    }

    return amount;
}


int main()
{
    int amount;
    int maxRange;

    std::cout<<"What is the max range of numbers you want tested for being prime? ";
    std::cin>>maxRange;

    amount = primes(maxRange);

    return amount;
}
