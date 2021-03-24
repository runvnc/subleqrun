import sys
from readchar import readchar

def run(mem):
    codePos = 0
    while codePos >= 0:
        a, b, c = mem[codePos:codePos+3]
        if a == -1:
            mem[b] += ord(readchar())
            codePos += 3
        elif b == -1:
            print(chr(mem[a]), end='')
            codePos += 3
        else:
            mem[b] = mem[b] - mem[a]
            if mem[b] <= 0:
                codePos = c
            else:
                codePos += 3