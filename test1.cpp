#include<bits/stdc++.h>
using namespace std;

int n;
int arr[105][105];
vector<int> adj[105];
bool visited[105];
vector<int> lt[105];

void dfs(int u,int cnt)
{
    visited[u] = true;
    lt[cnt].push_back(u);
    for(auto x : adj[u])
    {
        if(!visited[x])
        {
            dfs(x,cnt);
        }
    }
}

