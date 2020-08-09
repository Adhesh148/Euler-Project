/******************************************
* AUTHOR : AdheshR *
* Euler Problem: 019 *
* Problem Statement: *
* Comment: Have to do the date2Day function - something wrong with it.*
******************************************/
#include <bits/stdc++.h>
using namespace std;
int date2Day(int Y,int M,int D);
int countSundays(int Y1,int M1,int D1,int Y2,int M2,int D2);
int main()
{
	int T;
	cin>>T;

	for(int t=0;t<T;++t)
	{
		int Y1,M1,D1,Y2,M2,D2;
		cin>>Y1>>M1>>D1;
		cin>>Y2>>M2>>D2;
		cout<<countSundays(Y1,M1,D1,Y2,M2,D2)<<endl;
	}
}

int countSundays(int Y1,int M1,int D1,int Y2,int M2,int D2)
{
	if(D1!=1)
	{
		D1 = 1;
		++M1;
	}

	int count = 0;

	while((Y1<Y2) || ((Y1 == Y2) && (M1<=M2)))
	{
		if(date2Day(Y1,M1,D1) == 0)
		{
			// cout<<Y1<<"-"<<M1<<"-"<<D1<<endl;
			++count;
		}

		// cout<<Y1<<"-"<<M1<<"-"<<D1<<endl;
		++M1;
		if(M1>12)
		{
			M1 = 1;
			++Y1;
		}
	}
	return count;
}

int date2Day(int Y,int M,int D)
{
	int MC[] = {0,3,3,6,1,4,6,2,5,0,3,5};
	int Y1 = Y%100;
	int Y2 = floor(Y/100);

	int CC = Y2%4;
	if(CC == 1)	
		CC = 5;
	else if(CC == 2)
		CC == 3;
	else if(CC == 3)
		CC = 1; 
	
	int F = D + MC[M-1] + (Y1-1) + floor((Y1-1)/4) + CC;

	if(((Y%4 == 0 && Y%100 !=0) || (Y%100 == 0 && Y%400 == 0)) && (M>2))
	{
		// cout <<Y<<M<<endl;
		++F;
		cout << F<<endl;
		
	}
	F = F%7;
	
	return F;
}