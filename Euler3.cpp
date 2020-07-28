/******************************************
* AUTHOR : AdheshR*
******************************************/
#include <bits/stdc++.h>
using namespace std;
void constructSeive(vector<bool> &seive, long long int maxN);
long long int findLargestPrime(long long int N,vector<bool> seive,long long int maxN);
bool isPrime(long long int n);

// Passed all TestCases.

int main()
{
    int T;
    cin>> T;
    long long int N[10];
    vector<bool> seive(1e6,true);

    long long int maxN = 0;
    for(int t=0;t<T;++t)
    {
        cin >> N[t];
        maxN = max(maxN,N[t]);
    }

    maxN = ceil(sqrt(maxN)) + 1;
    // cout << maxN<<endl;
    constructSeive(seive,maxN);


    for(int t=0;t<T;++t)
        cout<<findLargestPrime(N[t],seive,maxN)<<endl;    
    
}

void constructSeive(vector<bool> &seive, long long int maxN)
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

long long int findLargestPrime(long long int N,vector<bool> seive,long long int maxN)
{
    long long int LPrime=0;

    for(long long int i=2;i<=ceil(sqrt(N));++i)
    {

        if(N%i == 0)
        {
            if(seive[i] == true)
                LPrime = max(LPrime,i);
            
            if((N/i) < maxN)
            {
            	if(seive[N/i] == true)
               		LPrime = max(LPrime,N/i);
            }
            else if(isPrime(int(N/i)))
            {
            	LPrime = max(LPrime,N/i);
            }
            
        }
    }

    if(LPrime == 0)
        LPrime = N;
    
    return LPrime;
}

bool isPrime(long long int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (long long int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 