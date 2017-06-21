# primefinder
Finds prime numbers
I have devised of 2 different algorithms to find prime numbers.
* 'prime.py' contains my initial algorithm (slowest)
* 'prime2.py' and 'primeCPP.cpp' contain my second algorithm (2nd fastest)
* 'prime3.py' contains the best algorithm I thought of without opening and reading files
* 'prime4.py' incorporates prime3's algorithm but storing the primes in a binary file
* 'prime5.py' is the fastest of them all, an altered form of prime3

Speed of each algorithm (for finding all primes from 1 to 100,000):
* 'Prime1.py': 216401    iterations in 50.0920000076 seconds
* 'Prime2.py': 227564781 iterations in 14.3220000267 seconds
* 'Prime3.py': 46264479  iterations in 2.84400010109 seconds
* 'Prime4.py': 46264479  iterations in 27.7479999065 seconds
* 'Prime5.py': 25002543  iterations in 2.56399989128 seconds
- 'Prime3.py' was ~5 seconds slower than 'Prime5.py' when calculating all primes from 1 to 1,000,000
