#include<bits/stdc++.h>
using namespace std;

int n,m, s,t;
vector<int> adj[1001];
bool visited[1001];
int check;
int par[1001];

void chuyen_ds_canh_sang_ds_ke()
{
    for(int i = 0; i< m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

void bfs(int u, int v)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        
        if(v == t)
        {
            check = true;
            return;
        }
        for(int x : adj[v])
        {
            if(!visited[x])
            {
                q.push(x);
                par[x] = v;
                visited[x] = true;
            }
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

        for(int i = 0; i< n; i++)
        {
            visited[i] = false;
            adj[i]. clear();
            check = false;
            par[i] = 0;
        }
        chuyen_ds_canh_sang_ds_ke();
        for(int i = 0; i< n; i++)
        {
            sort(adj[i].begin(), adj[i].end());
        }
        bfs(s,t);
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
                x = par[x];
            }

            reverse(path.begin(), path.end());

            for(auto i : path)
            {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}