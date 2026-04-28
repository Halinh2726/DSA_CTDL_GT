#include<bits/stdc++.h>
using namespace std;

int n,m;
int s, t;
vector<int> adj[1001];
bool visited[1001];
bool check;
int parent[1001];

void chuyen_ds_canh_sang_ds_ke()
{
    for(int i = 0; i< m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

void dfs(int u,int t)
{
    visited[u] = true;
    if(u == t)
    {
        check = true;
        return;
    }
    
    for(auto v : adj[u])
    {
        if(!visited[v])
        {
            parent[v] = u;
            dfs(v,t);
            if(check) return;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> s >> t;
        for(int i = 0; i < n; i++)
        {
            adj[i].clear();
            visited[i] = false;
            check = false;
            parent[i] = 0;
        }
        chuyen_ds_canh_sang_ds_ke();
        for(int i = 1; i <= n; i++)
        {
            sort(adj[i].begin(), adj[i].end());
        }
        dfs(s,t);
        
        if(!check)
        {
            cout << "-1\n";
        }
        else
        {
            vector<int> path;
            int x = t;

            while(x != 0)
            {
                path.push_back(x);
                x = parent[x];
            }

            
            reverse(path.begin(), path.end());

            for(int v : path)
                cout << v << " ";
        }
        cout <<"\n";
    }
    return 0;
}