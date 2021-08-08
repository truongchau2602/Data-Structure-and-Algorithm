#include<iostream>
using namespace std;
int main()
{
    int num_obj = 6;
    int cap = 10;
    int w[6] = {3,2,6,1,7,4};
    int v[6] = {7,10,2,3,2,6};
    int K[num_obj][cap+1];
    for (int i=0;i<6;i++)
    {
        for(int j=0;j<11;j++)
            K[i][j] = -1;
    }

    for(int i=0;i<num_obj;i++)
    {
        K[i][0] = 0;
    }
    for(int j = 0; j<cap+1;j++)
    {
        if(w[0]<=j)
            K[0][j]=v[0];
        else
            K[0][j]=0;
    }
    /*
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<11;j++)
        {
            cout<<K[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    for (int i=1;i<num_obj;i++)
    {
        for(int j=1;j<cap+1;j++)
        {
            /*
            if(j>=w[i] && K[i-1][j-w[i]] +v[i]>K[i-1][j])
            {
                K[i][j]= K[i-1][j-w[i]]+v[i];
            } else
                K[i][j] = K[i-1][j];

            */
            if(w[i]>j)
            {
                K[i][j] = K[i-1][j];
                continue;
            }

            if( K[i-1][j] > (K[i-1][j-w[i]] + v[i]))
            {
                K[i][j] = K[i-1][j];
            }
            else
                K[i][j] = K[i-1][j-w[i]] + v[i];


        }
    }





    for(int i=0;i<6;i++)
    {
        for(int j=0;j<11;j++)
        {
            cout<<K[i][j]<<" ";
        }
        cout<<endl;
    }

}
