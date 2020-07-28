/******************************************
* AUTHOR : AdheshR*
******************************************/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >>T;

    for(int t=0;t<T;++t)
    {
        long long int N;
        cin >> N;

        if(N%2 == 1)
            cout << -1 << endl;
        else
        {
            long long int a,b,c;
            a = 1;

            long long int maxProd = -1;

            //optimized while condition from N - 2
            while(a <= N/3)
            {
                b = (N*N/2 - N*a)/(N-a);
                c = (N - a - b);
                if((N == a+b+c) && (a*a + b*b == c*c))
                    maxProd = max(maxProd,a*b*c);

                a = a+1;
            }

            cout << maxProd<<endl;

        }

    }
}
