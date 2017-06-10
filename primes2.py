#This program was a result of my first idea of finding primes 
import time

def main(): 
    maxRange = 1000000#int(raw_input("What is the max range of numbers you want tested for being prime? ")) 
    
    if maxRange % 2 == 0: #To avoid even number decrements
        maxRange -= 1

    with open('primelist.bin', 'wb+') as file:
        file.write('2 ')
        
        for i in xrange(3, maxRange +1, 2):
            for j in xrange(3, i, 2):
                if i % j == 0:
                    break
            else:
                file.write(str(i) + ' ')
        
        file.seek(0)
        num = 0
        for line in file:
            for num, nul in enumerate(line.split(' ')):
                pass
        print 'Total primes: %d' % num

if __name__ == '__main__':
    start_time = time.time()
    
    main()
    
    print("--- %s seconds ---" % (time.time() - start_time))
    raw_input()

                