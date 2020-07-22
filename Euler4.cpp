/******************************************
* AUTHOR : AdheshR*
******************************************/
#include <bits/stdc++.h>
using namespace std;

bool ProductCheck(int number);

int main()
{
	int T;
	cin >> T;
	for(int i=0;i<T;++i)
	{
		int N;
		cin >> N;
		int n = N;
		int a,b,c;

		a = floor(N/100001);
		n = N - a*100001; 
		b = floor(n/10010);
		n = n - b*10010; 
		c = floor(n/1010);

		int flag = false;
		for(int j=a;j>=1;--j)
		{
			for(int k=b;k>=0;--k)
			{
				for(int m=c;m>=0;--m)
				{
					int number = j*(100000) + k*(10000) + m*(1000) + m*(100) + k*(10) + j;
					if(number > N)
						continue;
					else
					{
						flag = ProductCheck(number);
						if(flag)
						{
							cout << j<<k<<m<<m<<k<<j<<endl;
							break;
						}
					}
				}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
	}
}

bool ProductCheck(int number)
{
	int upperBound = sqrt(number) + 1;
	if(upperBound > 999)
		upperBound = 999;
	int lowerBound = 100; // Lowest 3 digit number

	for(int i=lowerBound;i<=upperBound;++i)
	{	
		if(number%i == 0 && ((number/i)/100 > 0) && ((number/i)/1000 == 0) && (i*(number/i) == number))
		{
			//cout << number << " "<<i<<" "<<number/i<<endl;
			return true;
		}
	}

	return false;
}