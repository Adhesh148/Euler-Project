/******************************************
*AUTHOR : AdheshR*
*Euler Problem: 020*
*Problem Statement: Find the sum of the digits in the number N!*
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define MAX 3000

void updateSum(vector<long long int> &sumDigits,vector<int> &digits,vector<pair<int,int>> N,int uB);
long long int computeSum(vector<int> &digits, int stepsMult,int uB);

int main()
{
    int T;
    cin >> T;

    vector<pair <int,int>> N;
    int input;
    for(int t=0;t<T;++t)
    {
        cin>>input;
        N.push_back(make_pair(input,t));
    }

    sort(N.begin(),N.end());

    vector<int> digits(MAX+4,0);
    digits[0] = 1;

    vector<long long int> sumDigits(T,0);
    updateSum(sumDigits,digits,N,T);

    for(int t=0;t<T;++t)
        cout << sumDigits[t]<<endl;

    
}

void updateSum(vector<long long int> &sumDigits,vector<int> &digits,vector<pair<int,int>> N,int uB)
{
    int prev = 1;
    int next = 1;
    for(int i=0;i<uB;++i)
    {
        next = N[i].first;
        if(next == 1 || next == 0)
            sumDigits[N[i].second] = 1;
        else if(next == prev)
            sumDigits[N[i].second] = sumDigits[N[i-1].second];
        else
            sumDigits[N[i].second] = computeSum(digits,prev+1,next);
        prev = N[i].first;
    }

}

long long int computeSum(vector<int> &digits, int stepsMult,int uB)
{

    long long int sumD = 0;
    int i = 0,carry = 0,product = 1;
    while(stepsMult<=uB)
    {
        carry = 0,product = 1,i=0;
        while(i<MAX)
        {
            product = digits[i]*stepsMult + carry;
            digits[i] = product%10;
            carry = int(product/10);
            ++i;
        }

        ++stepsMult;
    }
    
    i =0;
    while(i<MAX)
    {
        sumD = sumD + digits[i];
        i = i+1;
    }

    return sumD;
    
}    