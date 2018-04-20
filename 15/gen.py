#!/usr/bin/env python
from cyaron import *
import random
for di in range(1,11):
    print di
    td=IO(file_prefix='fib',data_id=di)
    T=100000
    td.input_writeln(str(T))
    for s in range(T):
        u=1
        for t in range(3):
            if random.randint(0,2)==0:
                break
            u*=10
        a,b,c,d=0,0,0,0
        while a+b<1 or c+d<1:
            a=random.randint(0,u)
            b=random.randint(0,u)
            c=random.randint(0,u)
            d=random.randint(0,u)
            if di==3 or random.randint(0,11)==0:
                b,d=0,0
            if di==4 or di==5 or random.randint(0,11)==0:
                b,c=0,0
        u=1
        for t in range(18):
            if random.randint(0,6)==0:
                break
            u*=10
        if di<=2:
            u=10
        n=random.randint(1,u)
        td.input_writeln(n,a,b,c,d)
    print 'done generating..'
    td.output_gen('fib')