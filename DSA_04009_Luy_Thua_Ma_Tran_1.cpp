#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
int n,k;
int a[15][15];

int luythua(int tmp[15][15], int a)
{
    if(a == 0) 
    {
        for(int i = 1; i<= n; i++)
            for(int j = 1; j<= n; j++)
                if(i == j)
                    return tmp[i][j] = 1;
    }
    if(a == 1)
    {
        for(int i = 1; i<= n; i++)
            for(int j = 1; j<= n; j++)
                return tmp[i][j];
    }

   

}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1; i<= n; i++)
            for(int j = 1; j<= n; j++)
                cin >> a[i][j];
        
    }
}