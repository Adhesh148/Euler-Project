/******************************************
* AUTHOR : AdheshR*
******************************************/
#include <bits/stdc++.h>
using namespace std;
long long int getTerm(vector<long long int> &terms,long long int i);
void constructTerms(vector<long long int> &terms,long long int maxN);

// Wrong Somewhere. Fails all but one. 

int main()
{
	int T;
	cin >> T;

	long long int maxN =0;
	vector<long long int> N(T);

	for(int t=0;t<T;++t)
	{
		cin>>N[t];
		maxN = max(maxN,N[t]);
	}

	maxN = maxN;
	vector<long long int> terms(1e9,-1);
	terms[1] = 1;
	terms[2] = 2;
	constructTerms(terms,maxN);
	
	long long int chainMax = 0;
	long long int chainIndex  = 0;
	for(int t=0;t<T;++t)
	{
		if(N[t] == 2)
			cout << 2<<endl;
		else if(N[t] == 1)
			cout << 1<<endl;
		else
		{
			for(int j=3;j<=N[t];++j)
			{
				if(terms[j]>=chainMax)
				{
					chainIndex = j;
					chainMax = terms[j];
				}
			}
			cout << chainIndex<<endl;
		}
	}

}

void constructTerms(vector<long long int> &terms,long long int maxN)
{
	for(int i=3;i<=maxN;++i)
		terms[i] = getTerm(terms,i);
}

long long int getTerm(vector<long long int> &terms,long long int i)
{
	if(terms[i] != -1)
		return terms[i];
	else
	{
		if(i%2 == 0)
		{
			terms[i] = getTerm(terms,i/2) + 1;
			return getTerm(terms,i/2) + 1;
		}
		else
		{
			terms[i] = getTerm(terms,3*i + 1) + 1;
			return getTerm(terms,3*i+1) + 1;
		}
	}
}