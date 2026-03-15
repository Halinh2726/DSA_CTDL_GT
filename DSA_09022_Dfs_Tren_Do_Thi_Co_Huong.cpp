#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
bool visited[1001];

void dfs(int u)
{
    cout << u <<" ";
    visited[u] = true;
    for(auto v: adj[u])
    {
        if(!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        int start;
        cin >> start;
        for(int i = 0; i< n;i++)
            adj[i].clear();
        for(int i = 0; i<m; i++)
        {
            int x,y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        memset(visited, false, sizeof(visited));
        dfs(start);
        cout << "\n";
    }
    return 0;
}