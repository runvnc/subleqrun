import sys

from readchar import readchar

def run(mem):
    codePos = 0
    mem = mem + [0] * 65536
    while codePos >= 0:
        a, b, c = mem[codePos:codePos+3]        
        if a == -1:
            mem[b] = ord(readchar())
            if mem[b] == 3:
                sys.exit(0)
            codePos += 3
        elif b == -1:
            sys.stdout.buffer.write(bytes([mem[a]]))
            sys.stdout.buffer.flush()
            codePos += 3
        else:
            mem[b] = mem[b] - mem[a]
            if mem[b] <= 0:
                codePos = c
            else:
                codePos += 3
