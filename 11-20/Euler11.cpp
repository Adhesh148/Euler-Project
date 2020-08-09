/******************************************
* AUTHOR : AdheshR *
* Euler Problem: 011 *
* Problem Statement: What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20 * 20 grid? *
* Comment: Look at the diagonal once more. Passes all test cases.*
******************************************/
#include <bits/stdc++.h>
using namespace std;
long long int getHorizontalMax(vector<vector<int>> grid);
long long int getVerticalMax(vector<vector<int>> grid);
long long int getDiagonalMax(vector<vector<int>> grid);

int main()
{
	vector<vector<int>> grid(20,vector<int>(20));
	for(int i=0;i<20;++i)
		for(int j=0;j<20;++j)
			cin>>grid[i][j];

	long long int HMax,VMax,DMax;
	HMax = getHorizontalMax(grid);
	VMax = getVerticalMax(grid);
	DMax = getDiagonalMax(grid);

	// cout<<HMax<<endl;
	// cout<<VMax<<endl;
	// cout<<DMax<<endl;
	cout << max(HMax,max(VMax,DMax))<<endl;


}

long long int getHorizontalMax(vector<vector<int>> grid)
{
	long long int Prod = 0;
	long long int MovingProd  = 1;

	int i=0,j=0;
	while(i<20)
	{
		MovingProd = grid[i][0] * grid[i][1] * grid[i][2] * grid[i][3];
		Prod = max(Prod,MovingProd);
		j = 1;
		while(j<17)
		{
			MovingProd = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
			Prod = max(Prod,MovingProd);
			++j;
		}
		++i;
	}

	return Prod;
}

long long int getVerticalMax(vector<vector<int>> grid)
{
	long long int Prod = 0;
	long long int MovingProd  = 1;

	int i=0,j=0;
	while(i<20)
	{
		MovingProd = grid[0][i] * grid[1][i] * grid[2][i] * grid[3][i];
		Prod = max(Prod,MovingProd);
		j = 1;
		while(j<17)
		{

			MovingProd = grid[j][i] * grid[j+1][i] * grid[j+2][i] * grid[j+3][i];
			Prod = max(Prod,MovingProd);
			++j;
		}
		++i;
	}
	return Prod;
}

long long int getDiagonalMax(vector<vector<int>> grid)
{
	long long int Prod = 0;
	long long int MovingProd  = 1;

	for(int i=0;i<20;++i)
	{
		for(int j=0;j<20;++j)
		{
			if((i<17) && (j>=4))
			{
				MovingProd = grid[i][j];
				for(int p=1;p<4;++p)
					MovingProd *= grid[i+p][j-p];

				Prod = max(Prod,MovingProd);
			}

			if((j<17) && (i<17))
			{
				MovingProd = grid[i][j];
				for(int p=1;p<4;++p)
					MovingProd *= grid[i+p][j+p];

				Prod = max(Prod,MovingProd);
			}
		}
	}

	return Prod;
}