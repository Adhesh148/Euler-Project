#!/bin/python3

import sys
import math

def countDiv(number):
    count = 0
    if(number == 1):
        return 1 
    for i in range(1,math.ceil(math.sqrt(number))):
        if(number % i == 0):
            count = count + 2
    if(math.floor(math.sqrt(number)) == math.ceil(math.sqrt(number))):
        count = count + 1
    return count

result = [1]
number = 1
k = 1
for i in range(1,1001):	
	while(countDiv(number) <= i):
		k = k + 1
		number = (k*(k+1))/2 

	result.append(int((k*(k+1))/2))

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(result[n])
    
    
