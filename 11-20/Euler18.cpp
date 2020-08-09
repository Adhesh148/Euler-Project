/******************************************
*AUTHOR : AdheshR*
*Euler Problem: 018*
*Problem Statement: By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is ____.*
*Comment: This is recursive solution aka brute force. The DP solution is required for larger N. It will be done in Euler 69 probably.*
******************************************/
#include <bits/stdc++.h>
using namespace std;
int maxPath(vector<vector<int>> numbers,int N,int pathCost,int row,int i);

int main()
{
	int T;
	cin>> T;

	int N;
	for(int t=0;t<T;++t)
	{
		cin>>N;
		vector<vector<int>> numbers(N);
		for(int i=0;i<N;++i)
		{
			numbers[i] = vector<int>(i+1);
			for(int j=0;j<i+1;++j)
				cin>>numbers[i][j];
		}
		// cout << numbers[0][0]<<endl;
		cout << maxPath(numbers,N,numbers[0][0],1,0)<<endl;
	}
}

int maxPath(vector<vector<int>> numbers,int N,int pathCost,int row,int i)
{
	if(row >= N)
		return pathCost;
	else
		return max(maxPath(numbers,N,pathCost+numbers[row][i],row+1,i),maxPath(numbers,N,pathCost+numbers[row][i+1],row+1,i+1));

}