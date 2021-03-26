import sys
from readchar import readchar

def run(mem):
    codePos = 0
    mem = mem + [0] * 65536
    printing = False
    lastB = 0
    while codePos >= 0:
        a, b, c = mem[codePos:codePos+3]        
        if a == -1:
            sys.stdout.buffer.flush()
            mem[b] = ord(readchar())
            if mem[b] == 3:
                sys.exit(0)
            codePos += 3
        elif b == -1:
            sys.stdout.buffer.write(bytes([mem[a]]))
            printing == True
            codePos += 3
        else:
            mem[b] = mem[b] - mem[a]
            if mem[b] <= 0:
                codePos = c
            else:
                codePos += 3
        if printing and mem[b] != -1:
            sys.stdout.buffer.flush()
            printing = False
        