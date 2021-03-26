#!/usr/bin/python3

from subleq import *

fname = sys.argv[1]

with open(sys.argv[1],'r') as f:
    text = f.read()

lines = text.split('\n')
list = []
for line in lines:
    list_ = line.split(' ')
    for item in list_:
        if item != '':
            list.append(int(item))
        
run(list)
