#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int n,m;
bool visited[MAXN];
vector<int> adj[MAXN];
vector<int> radj[MAXN];

void chuyendscanhsangdske()
{
    cin >> n >> m;
    for(int i = 0; i< m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void bfs(int s, vector<int> g[])
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
}