/******************************************
* AUTHOR : AdheshR*
******************************************/
#include <iostream>
#include <cmath>
using namespace std;
long long int countDivisors(long long int number);
void preCompute(int result[]);

//  Still Working on Answer;

int main()
{
	int result[1001];
	preCompute(result);

	int T;
	cin >> T;
	for(int t=0;t<T;++t)
	{
		int N[T];
		cin >> N[t];
		cout << result[N]<<endl;
	}
}

void preCompute(int result[])
{
	long long int number = 0;
	int k = 0;
	for(int i=0;i<=1000;++i)
	{
		while(number <= i)
		{
			++k;
			number = countDivisors(k * (k+1)/2);
		}
		result[i] = k * (k+1)/2;
	}
}

long long int countDivisors(long long int number)
{
	long long int count = 0;
	if(number == 1)
		return 1;
	for(int i=1;i<ceil(sqrt(number));++i)
	{
		if(number % i == 0)
			count = count + 2;
	}
	if(floor(sqrt(number)) == ceil(sqrt(number)))
		count = count + 1;
	return count;
}