#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t; cin >>t;
    int n; cin >> n;
    int a[n+1][n+1];
    vector<int> degIn(n+1,0), degOut(n+1,0);
    vector<pair<int,int>> adj;

    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] != 10000 && a[i][j] != 0)
            {
                ++degIn[j];
                ++degOut[i];
                adj.push_back({i,j});
            }
        }
    }

    if(t==1)
    {
        for(int i = 1; i<= n; i++)
            cout << degIn[i] << " " << degOut[i] <<"\n";
    }
    if(t==2)
    {
        int sz = adj.size();
        cout << n << " " << sz << "\n";
        for(auto x : adj)
        {
            cout << x.first << " " << x.second << " " << a[x.first][x.second] << "\n";
        }
    }
    return 0;
}