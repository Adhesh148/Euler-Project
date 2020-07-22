/******************************************
* AUTHOR : AdheshR*
******************************************/
#include <bits/stdc++.h>
using namespace std;

// Problem Statement:
// ------------------
// Find the greatest product of K consecutive digits in the N-digit number. 

int main()
{
	int T;
	cin>>T;

	for(int i=0;i<T;++i)
	{
		int N,K;
		cin>>N>>K;
		// cout << N<<K;

		int number[N];

		for(int j=0;j<N;++j)
			scanf("%1d",&number[j]);

		long long int Prod = 1;
		long long int MovingProd = 1;

		// Inital Value of Moving Sum
		for(int j=0;j<K;++j)
			MovingProd *= number[j];

		Prod = MovingProd;

		int j=1;
		while(j<N-K+1)
		{	
			// In-case zero between stream of digits, have to calculate again because prev mul not in memory(MovingProd)
			if(number[j-1] == 0)
			{
				MovingProd = 1;
				for(int p=j;p<j+K;++p)
					MovingProd = MovingProd * number[p]; 
			}
			else
				MovingProd = MovingProd/number[j-1] * number[j+K-1];

			Prod = max(Prod,MovingProd);
			++j;
		}

		cout <<Prod<<endl;
	}
}