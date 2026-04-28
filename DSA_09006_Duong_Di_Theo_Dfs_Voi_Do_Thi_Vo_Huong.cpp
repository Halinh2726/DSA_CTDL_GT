#include<bits/stdc++.h>
using namespace std;

int v,e,s,t;
bool visited[1001];
vector<int> adj[1001];
int parent[1001];
void reset()
{
    for(int i = 1; i<= v; i++)
    {
        visited[i] = false;
        adj[i].clear();
        parent[i] = -1; 
    }
}
void chuyen_ds_canh_ds_ke()
{
    for(int i = 1; i <= e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int u)
{
    
    visited[u] = true;
    for(auto v : adj[u])
    {
        // Neu dinh v ch dc tham, goi dfs toi dinh v
        if(!visited[v])
        {
            parent[v] = u;
            dfs(v);
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> v >> e >> s >> t;
        reset();
        chuyen_ds_canh_ds_ke();

        dfs(s);

        if(!visited[t])
        {
            cout << -1 << "\n";
        }
        else
        {
            vector<int> path;
            int cur = t;
            while(cur != -1)
            {
                path.push_back(cur);
                cur = parent[cur];
            }
            reverse(path.begin(), path.end());

            for(auto x: path) cout << x <<" ";
            cout <<"\n";
        }
    }
}


