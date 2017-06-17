#This program was a result of my first idea of finding primes 
import time

def main(): 
    maxRange = 100#int(raw_input("What is the max range of numbers you want tested for being prime? ")) 
    primes = [2]
    
    if maxRange % 2 == 0: #To avoid even number decrements
        maxRange -= 1   

    for i in xrange(3, maxRange +1, 2):
        for j in primes:
            if j >= i/2 +1:
                break
            
            if i % j == 0:
                break
        else:
            primes.append(int(i))
        
    print 'Total primes: %d' % len(primes)

if __name__ == '__main__':
    start_time = time.time()
    
    main()
    
    print("Time taken: %s seconds" % (time.time() - start_time))
    raw_input()