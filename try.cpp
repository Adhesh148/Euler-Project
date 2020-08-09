/******************************************
* AUTHOR : AdheshR *
* Euler Problem: 011 *
* Problem Statement: What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20 * 20 grid? *
* Comment: *
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

    cout<<HMax<<endl;
    cout<<VMax<<endl;
    cout<<DMax<<endl;
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
            if(grid[i][j-1] == 0)
            {
                MovingProd = 1;
                for(int p =j;p<j+4;++p)
                    MovingProd = MovingProd * grid[i][p];
            }
            else
                MovingProd = MovingProd/grid[i][j-1] * grid[i][j+3];

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
            if(grid[j-1][i] == 0)
            {
                MovingProd = 1;
                for(int p =j;p<j+4;++p)
                    MovingProd = MovingProd * grid[p][i];
            }
            else
                MovingProd = MovingProd/grid[j-1][i] * grid[j+3][i];

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

    // First Half of Diagonal
    int i=0,j=0;
    while(i<17)
    {
        MovingProd = grid[0][i] * grid[1][i+1] * grid[2][i+2] * grid[3][i+3];
        Prod = max(Prod,MovingProd);
        j = 1;
        while(j<17-i)
        {
            if(grid[j-1][j+i-1] == 0)
                MovingProd = grid[j][j+i] * grid[j+1][j+i+1] * grid[j+2][j+i+2] * grid[j+3][j+i+3];
            else
                MovingProd = MovingProd/grid[j-1][j+i-1] * grid[j+3][j+i+3];

            Prod = max(Prod,MovingProd);
            ++j;
        }
        ++i;
    }

    cout << Prod<<endl;

    // Second Half of Diagonal
    i=1,j=0;
    while(i<17)
    {
        MovingProd = grid[i][0] * grid[i+1][1] * grid[i+2][2] * grid[i+3][3];
        Prod = max(Prod,MovingProd);
        j = 1;
        while(j<17-i)
        {
            if(grid[j+i-1][j-1] == 0)
                MovingProd = grid[j+i][j] * grid[j+i+1][j+1] * grid[j+i+2][j+2] * grid[j+i+3][j+3];
            else
                MovingProd = MovingProd/grid[j+i-1][j-1] * grid[j+i+3][j+3];

            Prod = max(Prod,MovingProd);
            ++j;
        }
        ++i;
    }
    cout << Prod<<endl;
    return Prod;
}

/**

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

    cout<<HMax<<endl;
    cout<<VMax<<endl;
    cout<<DMax<<endl;
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

    // First Half of Diagonal
    int i=0,j=0;
    while(i<17)
    {
        MovingProd = grid[0][i] * grid[1][i+1] * grid[2][i+2] * grid[3][i+3];
        Prod = max(Prod,MovingProd);
        j = 1;
        while(j<17-i)
        {
            MovingProd = grid[j][j+i] * grid[j+1][j+i+1] * grid[j+2][j+i+2] * grid[j+3][j+i+3];
            Prod = max(Prod,MovingProd);
            ++j;
        }
        ++i;
    }

    cout << Prod<<endl;

    // Second Half of Diagonal
    i=1,j=0;
    while(i<17)
    {
        MovingProd = grid[i][0] * grid[i+1][1] * grid[i+2][2] * grid[i+3][3];
        Prod = max(Prod,MovingProd);
        j = 1;
        while(j<17-i)
        {
            MovingProd = grid[j+i][j] * grid[j+i+1][j+1] * grid[j+i+2][j+2] * grid[j+i+3][j+3];
            Prod = max(Prod,MovingProd);
            ++j;
        }
        ++i;
    }
    cout << Prod<<endl;
    return Prod;
}
**/