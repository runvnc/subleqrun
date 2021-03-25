import sys
from readchar import readchar

def checksize(mem,a,b):
    l = max(a,b)
    while len(mem) <= l:
        mem.append(0)

def run(mem):
    codePos = 0
    cnt = 0
    mem.append(0)
    mem.append(0)
    while codePos >= 0:
        cnt += 1
        a, b, c = mem[codePos:codePos+3]
        if a == -1:
            mem[b] = ord(readchar())
            codePos += 3
        elif b == -1:
            print(chr(mem[a]), end='')
            sys.stdout.flush()
            codePos += 3
        else:
            checksize(mem,a,b)
            mem[b] = mem[b] - mem[a]
            if mem[b] <= 0:
                codePos = c
            else:
                codePos += 3
