import sys

def flattenlines(fname):
    data = []
    n = 0
    with open(fname,'r') as f:
        for line in f:
            if n>0: print(' ', end='')
            num1s,num2s,num3s = line.split(' ')
            print(int(num1s),end=' ')
            print(int(num2s),end=' ')
            print(int(num3s),end='')
            n += 1
    print()

if sys.argv[1]:
    flattenlines(sys.argv[1])
