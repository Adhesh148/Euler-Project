/******************************************
* AUTHOR : AdheshR*
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define MAX 40000

void updateSum(vector<long long int> &sumDigits,vector<int> &digits,vector<pair<int,int>> N,int uB);
long long int computeSum(vector<int> &digits, int stepsMult);

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
    int prev = 0;
    int next = 0;
    int stepsMult = 0;
    for(int i=0;i<uB;++i)
    {
        next = N[i].first;
        stepsMult = next - prev;
        sumDigits[N[i].second] = computeSum(digits,stepsMult);
        prev = N[i].first;
    }
}

long long int computeSum(vector<int> &digits, int stepsMult)
{

    long long int sumD = 0;
    int i = 0,carry = 0,product = 1;

    while(stepsMult>0)
    {
        carry = 0,product = 1,i=0;
        while(i<MAX)
        {
            product = digits[i]*2 + carry;
            digits[i] = product%10;
            carry = int(product/10);
            ++i;
        }
        --stepsMult;
    }
    
    i =0;
    while(i<MAX)
    {
        sumD = sumD + digits[i];
        i = i+1;
    }

    return sumD;
}

