#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
bool visited[1001];

void dfs(int u)
{
    visited[u] = true;
    for(int x: adj[u])
    {
        if(!visited[x]) dfs(x);
    }
}

void cnttplienthong()
{
    int ans = 0;
    // memset(visited, false, sizeof(visited));
    for(int i = 1; i<= n; i++)
    {
        if(!visited[i])
        {
            ans++;
            dfs(i);
        }
    }
    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i =1; i<= n; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }
        // memset(visited, false, sizeof(visited));
    for(int i= 0; i< m; i++)
    {
        int x, y;
        cin >> x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cnttplienthong();
    }
    return 0;
}