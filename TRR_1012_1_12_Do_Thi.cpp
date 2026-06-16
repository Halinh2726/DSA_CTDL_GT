#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t;
    cin >> t;
    int n;
    cin >> n;
    int mtx[n+1][n+1];
    
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= n; j++)
            cin >> mtx[i][j];
    }
    
    if(t==1)
    {
        vector<int> degin(n+1,0), degout(n+1,0);

        for(int i = 1; i<= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                degin[j] += mtx[i][j];
                degout[i] += mtx[i][j];
            }
        }

        for(int i = 1; i<= n; i++)
        {
            cout << degin[i] << " " << degout[i] << "\n";
        }
    }

    if(t== 2)
    {
        vector<pair<int,int>> adj;
        for(int i =1 ; i<= n; i++)
        {
            for(int j = 1; j<= n; j++)
            {
                if(mtx[i][j]) adj.push_back({i,j});
            }
        }

        cout << n << " " << adj.size() << "\n";
        for(auto x : adj)
        {
            cout << x.first << " " << x.second << "\n";
        }
    }
    return 0;
}