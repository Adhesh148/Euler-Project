

/******************************************
* AUTHOR : AdheshR*
******************************************/
// Euler #6
#include <bits/stdc++.h>
using namespace std;

// The sum of the squares of the first ten natural numbers is,
// 1^2+2^2+...+10^2=385
// The square of the sum of the first ten natural numbers is,
// (1+2+...+10)^2=55^2=3025
// Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025−385=2640
// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.


int main(){
  unsigned int t;
  scanf("%d",&t);
  for(unsigned int i=0;i<t;++i){
      double n;
      scanf("%lf",&n);
      long double diff=0;
      
      diff =   pow((n*(n+1)/2),2)-((n*(n+1)*(2*n+1))/6);
      printf("%.Lf\n",diff);
  }
}