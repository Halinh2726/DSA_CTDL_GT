#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT", "w", stdout);
    int t;
    cin >> t;
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1, vector<int>(n+1,0));
    vector<int> tmp(n+1,0);

    for(int i = 1; i <= n; i++)
    {
        int m; cin >> m;
        tmp[i] = m;
        while(m--)
        {
            int x; cin >> x;
            adj[i][x] = 1;
            adj[x][i] = 1;
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            int deg = 0;
            for (int j = 1; j <= n; j++)
                deg += adj[i][j];
            cout << deg << " ";
        }
    }

    if(t==2)
    {
        cout << n << "\n";
        for(int i = 1; i<= n; i++)
        {
            for(int j = 1; j<= n ; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}