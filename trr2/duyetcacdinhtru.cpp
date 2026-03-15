#include<bits/stdc++.h>
using namespace std;

int n;
int a[1005][1005];
vector<int> adj[1005];

int num[1005], low[1005];
bool visited[1005];
bool isArt[1005];
int timer;
int root, child;

void dfs(int u, int parent)
{
    visited[u] = true;
    num[u] = low[u] = ++timer;

    for(int v : adj[u])
    {
        if(v == parent) continue;

        if(!visited[v])
        {
            if(u == root) child++;

            dfs(v, u);

            low[u] = min(low[u], low[v]);

            if(u != root && low[v] >= num[u])
                isArt[u] = true;
        }
        else
        {
            low[u] = min(low[u], num[v]);
        }
    }
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j])
                adj[i].push_back(j);
        }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            root = i;
            child = 0;
            dfs(i, -1);

            if(child > 1)
                isArt[root] = true;
        }
    }

    for(int i = 1; i <= n; i++)
        if(isArt[i])
            cout << i << " ";

    return 0;
}