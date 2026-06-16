#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);  
    int t,n,m;
    cin >> t >> n >> m;
    vector<int> degIn(n+1,0), degOut(n+1,0);
    vector<pair<int,int>> adj;
    for(int i = 1; i<= m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj.push_back({x,y});
        ++degIn[y];
        ++degOut[x];
    }

    if(t==1)
    {
        for(int i = 1; i<= n; i++)
        {
            cout << degIn[i] << " " << degOut[i] << "\n";
        }
    }

    if(t==2)
    {
        vector<vector<int>> edge(n+1, vector<int>(m+1,0));

        for(int i = 0; i< m; i++)
        {
            int u = adj[i].first;
            int v = adj[i].second;

            edge[u][i] = 1;
            edge[v][i] = -1;
        }

        cout << n << " " << m << "\n";
        for(int i = 1; i<= n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cout << edge[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}