#!/bin/python3

import sys
import math

#SUM OF EVEN FIBONACCI SERIES:
# ---------------------------#
# Alternate Approach - Loop through the series.

# Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
# 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
# By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.



t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    f = []
    sumF = 2 
    f.append(0)
    f.append(2)
    while(f[-1] < n):
        f.append(4*f[-1] + f[-2])
        if(f[-1] > n):
            break
        sumF = sumF + f[-1]
    print(sumF)

