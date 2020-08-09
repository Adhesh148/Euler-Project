/******************************************
* AUTHOR : AdheshR *
* Euler Problem: 002 *
* Problem Statement: Sum of Even Fibonacci Terms less than N.*
* Comment: Formula Based Approach - Fails in just a single test case. *
******************************************/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int i=0;i<T;++i)
    {
        unsigned long long int N;
        cin >> N;

        unsigned long long int index =  floor(2.078087 * log(N) + 1.672276);
        index = index/3 + 1; 
        unsigned long long int sum = (((pow((2+sqrt(5)),index) - 1)/(1+sqrt(5))) - ((pow((2-sqrt(5)),index) - 1)/(1-sqrt(5))))/sqrt(5);
        cout << sum<<endl;

    }
}