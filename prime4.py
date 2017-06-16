#This program was a result of my first idea of finding primes 
import time

def main(): 
    maxRange = 1000000#int(raw_input("What is the max range of numbers you want tested for being prime? "))
    
    if maxRange % 2 == 0: #To avoid even number decrements
        maxRange -= 1
    
    with open('primelist.bin', 'wb+') as file:
        file.write('2')
    
        for guess in xrange(3, maxRange +1, 2):            
            file.seek(0)
            for lines in file:
                if guess % int(lines) is 0:
                    break
            else:
                file.write('\n' + bytes(guess))
            
        file.seek(0)
        num = 0
        for line in file:
            for primes in line.split():
                num += 1
        
        print 'Total primes: %d' % num
        
if __name__ == '__main__':
    start_time = time.time()
    
    main()
    
    print("Time taken: %s seconds" % (time.time() - start_time))
    raw_input()
