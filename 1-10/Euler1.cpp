/******************************************
* AUTHOR : AdheshR*
* Problem Statement: If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
	Find the sum of all the multiples of 3 or 5 below 1000.
* Comment: Direct Formula Based. *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MAX 100000
#define MOD 1000000007
#define dd double

int main()
{
	int T;
	cin >> T;
	for(int i=0;i<T;++i)
	{
		long int N;
		cin >> N;
		--N;
		cout <<((3*(N/3)*(N/3 + 1)) + (5*(N/5)*(N/5 + 1)) - (15*(N/15)*(N/15 + 1)) >> 1)<< endl;
	}
}
