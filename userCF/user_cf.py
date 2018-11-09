#!/usr/env python
# encoding:utf-8


A = [0.1, -1.0,  0.7,  0.8, -1.0, -1.0, -1.0, -1.0, 0.9]
B = [0.5,  0.4, -1.0,  0.4, -1.0, 0.3, -1.0, -1.0, 0.8]
C = [0.2, -1.0,  0.8,  0.7, -1.0, 0.1, -1.0, -1.0, 0.7]

U = {}
U['a'] = A
U['b'] = B
U['c'] = C

if __name__ == '__main__':
    for u in U.keys():
        for i in U.keys():
            if u == i:
                continue
            x = U[u]
            y = U[i]
            


    pass


