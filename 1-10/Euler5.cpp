#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Problem Statement:
-----------------
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

long int gcd(long long int a, long long int b);

int main() {
   int T;
   cin>>T;
   for(int i=0;i<T;++i)
   {
       int N;
       cin >> N;
       long long int result = 1;
       for(long long int i=1;i<=N;++i)
       {
           long int g = gcd(result,i);
           result = (i*result)/g;
       }
       cout<<result<<endl;
   }
}

long int gcd(long long int a, long long int b)
{
    if(b == 0)
        return a;
    else return gcd(b,a%b);
}
