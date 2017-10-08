# primefinder
Finds prime numbers
I have devised of 2 different algorithms to find prime numbers.
* 'prime.py' contains my initial algorithm (slowest)
* 'prime2.py' and 'primeCPP.cpp' contain my second algorithm (2nd fastest)
* 'prime3.py' contains the best algorithm I thought of without opening and reading files
* 'prime4.py' incorporates prime3's algorithm but storing the primes in a binary file
* 'prime5.py' is the fastest python script, an altered form of prime3
* 'primec.c' is the fastest of them all, a ported version of python4

Speed of each algorithm (for finding all primes from 2 to 100,000):
* 'prime1.py': 216401    iterations in 50.0920000076 seconds
* 'prime2.py': 227564781 iterations in 14.3220000267 seconds
* 'prime3.py': 46264479  iterations in 2.84400010109 seconds
* 'prime4.py': 46264479  iterations in 27.7479999065 seconds
* 'prime5.py': 25002543  iterations in 2.56399989128 seconds
* 'primec.c' : 704028    iterations in 0.216661      seconds
- 'prime3.py' was ~5 seconds slower than 'Prime5.py' when calculating all primes from 2 to 1,000,000
- 'primec.c' could calculate all primes from 2 to 100,000,000 in 681 seconds
