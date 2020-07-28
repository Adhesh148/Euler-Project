#!/bin/python3

import sys
import math

def constructSeive(seive,maxN):
	p = 2
	for i in range(2,maxN+1,1):
		if(seive[i] and (i*i <= maxN)):
			for j in range(i*i,maxN+1,i):
				seive[j] = False

def findLargestPrime(number,seive):
	LPrime = 0
	for i in range(2,math.ceil(math.sqrt(number))+1):
		if(number%i == 0):
			if(seive[i] == True):
				LPrime = max(LPrime,i)
			if(seive[number//i] == True):
				LPrime = max(LPrime,number//i)

	if(LPrime == 0):
		LPrime = number

	return LPrime

t = int(input().strip())
n = []
maxN = 0

for a0 in range(t):
    n.append(int(input().strip()))
    maxN = max(maxN,n[-1])

print(maxN)
# maxN = math.ceil(math.sqrt(maxN)) + 2
seive = [True for i in range(maxN+1)]
constructSeive(seive,maxN)

for number in n:
    print(findLargestPrime(number,seive))


