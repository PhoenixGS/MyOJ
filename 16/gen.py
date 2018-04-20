#!/usr/bin/env python
from cyaron import *
import random
for a in range(1,11):
    td=IO(file_prefix='box',data_id=a)
    T=50
    if a==1:
        T=49
    if a==7 or a==8:
        T=2
    td.input_writeln(str(T))
    for x in range(T):
        n=random.randint(1,3)
        if a<=1:
            pass
        elif a<=6:
            n=random.randint(1,1000)
        elif a<=8:
            n=random.randint(1,100000)
        else:
            n=random.randint(1,200000)
        k=random.randint(1,n)
        if a==2 or a==3 or (T==50 and x>=0 and x<=3 and a>5):
            k=1
        if a==4 or a==5 or (T==50 and x>=4 and x<=7 and a>5):
            n=(n+1)/2*2
            k=n/2
        td.input_writeln(n,k)
    td.output_gen('box')