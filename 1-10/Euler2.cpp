/******************************************
* AUTHOR : AdheshR*
******************************************/
#include <bits/stdc++.h>
using namespace std;

// SUM OF EVEN FIBONACCI SERIES:
// ---------------------------#
// Formula Based Approach - Fails in just a single test case. 

// Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
// 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.


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