#include<bits/stdc++.h>
using namespace std;


int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t;
    cin >> t;
    int n; cin >> n;

    int mtx[n+1][n+1];
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> mtx[i][j];
        }
    }

    if(t==1)
    {
        for(int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for(int j = 1; j<= n; j++)
            {
                if(mtx[i][j] != 10000 && mtx[i][j] != 0)
                {
                    ++cnt;
                }
            }
            cout << cnt << " ";
        }
        cout << "\n";
    }

    if(t==2)
    {
        vector<pair<int,int>> edges;

        for(int i = 1; i<= n; i++)
        {
            for(int j = i+1; j<= n; j++)
            {
                if(mtx[i][j] != 10000 && mtx[i][j] != 0)
                {
                    edges.push_back({i,j});
                }
            }
        }
        cout << n << " " << edges.size() << "\n";

        for(auto x : edges)
        {
            cout << x.first << " " << x.second << " " << mtx[x.first][x.second] << "\n";
        }
    }
    return 0;
}