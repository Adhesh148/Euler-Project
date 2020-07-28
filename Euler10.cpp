/******************************************
* AUTHOR : AdheshR*
******************************************/
#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.

Stratergy: Precompute Sum of Max N primes, use Eratosthenes Seive

*/

void constructSeive(vector<bool> &seive,int maxN);
void accumulateSum(vector<long long int> &sum,vector<bool> seive,int maxN);

int main()
{
	int T;
	cin>> T;

	vector<int> N(1e6);
	int maxN =0;

	for(int t=0;t<T;++t)
	{
		cin>>N[t];
		maxN = max(N[t],maxN);
	}

	vector<bool> seive(maxN+1,true);
	constructSeive(seive,maxN);

	vector<long long int> sum(maxN+1,0);
	accumulateSum(sum,seive,maxN);

	for(int t=0;t<T;++t)
		cout << sum[N[t]]<<endl;
}

void accumulateSum(vector<long long int> &sum,vector<bool> seive,int maxN)
{
	for(int i=2;i<=maxN;++i)
	{
		if(seive[i])
			sum[i] = sum[i-1] + i;
		else
			sum[i] = sum[i-1];
	}
}


void constructSeive(vector<bool> &seive,int maxN)
{
    // Do the Eratosthenes Seive upto maxN
    for(long long int p=2;p*p<=maxN;++p)
    {
        if(seive[p] == true)
        {
            for(long long int i = p*p; i<=maxN;i+=p)
                seive[i] = false;
        }
    }
}