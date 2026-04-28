#include<bits/stdc++.h>
using namespace std;

int n,m,s;
vector<vector<int>> adj;
vector<int> dist, par;

void bfs(int s)
{
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : adj[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u] +1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

void printpath(int i)
{
    vector<int> path;
    for(int v = i; v != -1; v = par[v])
    {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for(int j = 0; j< path.size(); j++)
    {
        if( j) cout << ' ';
            cout << path[j];
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> s;

        adj.assign(n+1,{});
        dist.assign(n+1, -1);
        par.assign(n+1, -1);
        for(int i = 1; i<= n;i++)
        {
            adj[i].clear();
            dist[i] = -1;
            par[i] = -1;
        }

        for(int i= 0; i< n; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bfs(s);

        for(int i= 1; i<= n; i++)
        {
            if(i == s) continue;
            if(dist[i] == -1) cout << "No path\n";
            else printpath(i);
        }   
    }
    return 0;
}