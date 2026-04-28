#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void reset()
{
    for(int i = 0; i<= n; i++)
    {
        adj[i].clear();
        
    }
}
void chuyen_ds_canh_sang_ds_ke()
{
    for(int i = 0; i< m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

bool bfs(int u, int t)
{
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        if(v == t) return true;
        for(int x : adj[v])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        reset();
        chuyen_ds_canh_sang_ds_ke();
        int q;
        cin >> q;
        while(q--)
        {
            int x,y;
            cin >> x >> y;
            if(bfs(x,y)) cout << "YES\n";
            else cout << "NO\n";
        }
        cout << "\n";
    }
    return 0;
}