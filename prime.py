#This program was a result of my first idea of finding primes 

def main(): 
    maxRange = int(raw_input("What is the max range of numbers you want tested for being prime? ")) 
    numRange= range(3, maxRange +1, 2) #currently has composites, they will be removed @end of program 
    primes = [2]
    
    while numRange: 
        repeat = 1 
        guess = numRange[0] 
        primes.append(numRange[0]) 
        
        while repeat * guess <= maxRange: 
            
            if repeat * guess in numRange: 
                numRange.remove(repeat * guess) 
            
            repeat += 1 
            
    print 'Total primes: %d, all primes: %s' % (len(primes), primes) 
    
if __name__ == '__main__':
    main()
    
    exit
