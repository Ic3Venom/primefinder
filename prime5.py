#This program was a result of my first idea of finding primes 

def main(): 
    maxRange = int(raw_input("What is the max range of numbers you want tested for being prime? ")) 
    primes = [2]
    
    if maxRange % 2 == 0: #To avoid even number decrements
        maxRange -= 1   

    for i in xrange(3, maxRange +1, 2):
        for j in primes:
            if i % j == 0:
                break
            
            if j > i//2:
                primes.append(int(i))
                break
        
    print 'Total primes: %d' % len(primes)
    raw_input()

if __name__ == '__main__':
    
    main()
