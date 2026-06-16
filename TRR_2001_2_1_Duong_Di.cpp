#include<bits/stdc++.h>
using namespace std;

int t,n,u,v;
int arr[105][105];
vector<int> adj[105];
bool visited[105];
int parent[105];


void dfs(int u)
{
    visited[u] = true;
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            visited[v] = true;
            parent[v] = u;
            dfs(v);
        }
    }
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> t >> n >>u >> v;
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j])
            {
                adj[i].push_back(j);
            }
        }
    }

    if(t==1)
    {
        int cnt = 0;
        for(int i= 1; i<= n ; i++)
        {
            if(arr[u][i] && arr[i][v])
            {
                ++cnt;
            }
        }
        cout << cnt << "\n";
    }

    if(t==2)
    {
        memset(visited, false, sizeof(visited));
        dfs(u);

        if(!visited[v]) cout <<  0 << "\n";
        else
        {
            vector<int> res;
            res.reserve(n+1);

            while( v != u)
            {
                res.push_back(v);
                v = parent[v];
            }
            res.push_back(u);

            reverse(res.begin(), res.end());
            for(int x : res) cout << x << " ";
            cout <<"\n";
        }
    }
    return 0;
}