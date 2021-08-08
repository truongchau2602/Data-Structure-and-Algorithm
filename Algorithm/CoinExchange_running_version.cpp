#include<iostream>
#include<algorithm>
using namespace std;
int coinChange(int n, int N)
{

}
int main()
{
    int N=11;
    int n=3;
    int d[n]={1,4,6};
    int table[n][N+1];
    int i,j;
    for (i = 0; i < n; i++)
    {
        table[i][0] = 0;
    }

    for (i=0; i < n; i++)
    {
        for(j=1; j < N+1; j++)
        {
            if (i==0)
                table[i][j] = table[i][j - d[i]] + 1;
            else if (j < d[i])
                table[i][j] = table[i-1][j];
            else
                table[i][j] = min(table[i-1][j], table[i][j-d[i]]+1);
        }
    }
    for (i=0; i < n; i++)
    {
        for(j=1; j < N+1; j++)
        {
            cout<<table[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"Min coins: "<< table[n-1][N];

}
