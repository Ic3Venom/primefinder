#This program was a result of my first idea of finding primes 

def main(): 
    maxRange = int(raw_input("What is the max range of numbers you want tested for being prime? ")) 
    
    if maxRange % 2 == 0: #To avoid even number decrements
        maxRange -= 1

    with open('primelist2.bin', 'wb+') as file:
        file.write('2 ')
        
        for i in xrange(3, maxRange +1, 2):
            for j in xrange(3, i, 2):
                if i % j == 0:
                    break
                
            else:
                file.write(str(i) + ' ')
        
        file.seek(0)
        num = -1
        
        for line in file:
            for i in line.split(' '):
                num += 1
                
        print 'Total primes: %d' % num
        raw_input()

if __name__ == '__main__':
    
    main()
