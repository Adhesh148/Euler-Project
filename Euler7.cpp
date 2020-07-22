/******************************************
* AUTHOR : AdheshR*
******************************************/
#include <bits/stdc++.h>
using namespace std;

long long int findNPrime(int N);
bool isPrime(long long int n) ;


int main()
{
	int T;
	cin>>T;

	for(int i=0;i<T;++i)
	{
		int N;
		cin>>N;
		long long int Nprime = findNPrime(N);
		cout<<Nprime<<endl;
	}
}

long long int findNPrime(int N)
{
	if(N == 1) return 2;
	if(N == 2) return 3;

	int count = 2;
	long int k = 1;


	while(count!=N)
	{
		long long int guess1 = 6*k - 1;
		long long int guess2 = 6*k + 1;
		++k;

		if(isPrime(guess1) && ++count == N)
			return guess1;

		if(isPrime(guess2) && ++ count == N)
			return guess2;
	}
}

bool isPrime(long long int n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 