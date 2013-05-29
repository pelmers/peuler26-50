#!/usr/bin/env python

import math

def triangular_number(n):
    return (n*(n+1)) / 2

def pentagonal_number(n):
    return (n*(3*n-1)) / 2

def hexagonal_number(n):
    return n * (2*n-1)

def is_triangular(n):
    t = int(math.sqrt(2*n+0.25) - 0.5)
    return triangular_number(t) == n

def is_pentagonal(n):
    p = int(math.sqrt(24*n+1)+1) / 6
    return pentagonal_number(p) == n

def is_hexagonal(n):
    h = int(math.sqrt(8*n+1)+1) / 4
    return hexagonal_number(h) == n

for h in range(1, 100000):
    hn = hexagonal_number(h)
    if (is_pentagonal(hn) and is_triangular(hn)):
        print hn
