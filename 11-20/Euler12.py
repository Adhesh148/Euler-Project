#!/bin/python3

import sys


def isPrime(guess) : 
  
    # Corner cases 
    if (guess <= 1) : 
        return False
    if (guess <= 3) : 
        return True
  
    # This is checked so that we can skip  
    # middle five numbers in below loop 
    if (guess % 2 == 0 or guess % 3 == 0) : 
        return False
  
    i = 5
    while(i * i <= guess) : 
        if (guess % i == 0 or guess % (i + 2) == 0) : 
            return False
        i = i + 6
  
    return True


def nextPrime(p):
	if(p == 2):
		return 3
	elif(p==3):
		return 5
	else:
		if((p+1)% 6 == 0):
			k = (p+1)/6
			guess1 = 6*k + 1
			if(isPrime(guess1)):
				return guess1
		else:
			k = (p-1)/6

		k = k + 1
		while(True):
			guess1 = 6*k - 1
			guess2 = 6*k + 1
			if(isPrime(guess1)):
				return guess1
			elif(isPrime(guess2)):
				return guess2
			else:
				k = k + 1


def countDiv(number):
	p = 2
	numDiv = 1
	while(p<=number):
		chosen = p
		count = 0
		if(number%chosen == 0):
			while (number%chosen == 0):
				number = number/chosen
				count = count + 1
		numDiv = numDiv * (count+1)
		p = nextPrime(p)
	return numDiv

t = int(input().strip())
result = []
number = 1
k = 1
for i in range(1,1001):	
	while(countDiv(number) <= i):
		k = k + 1
		number = (k*(k+1))/2 

	result.append(int((k*(k+1))/2))

for a0 in range(t):
    n = int(input().strip())
    print(result[n-1])
    
