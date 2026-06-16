#include<bits/stdc++.h>
using namespace std;

int t,n,u,v;
vector<int> adj[1005];
int arr[1005][1005];
bool visited[1005];
int parent[1005];

void bfs(int u, int v)
{
    visited[u] = true;

    queue<int> q;
    q.push(u);

    while(!q.empty())
    {
        int x = q.front(); q.pop();
        if(x == v) return;

        for(auto y : adj[x])
        {
            if(!visited[y])
            {
                q.push(y);
                parent[y] = x;
                visited[y] = true;
            }
        }
    }
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> t;
    cin >> n >> u >>v;
    for(int i = 1; i<= n;i++)
    {
        for(int j = 1; j<= n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j])
            {
                adj[i].push_back(j);
            }
        }
    }

    if(t==1)
    {
        int cnt = 0;
        for(int i= 1; i<= n; i++)
        {
            if(arr[u][i] && arr[i][v])
                ++cnt;
        }
        cout << cnt <<"\n";
    }

    if(t==2)
    {
        memset(visited, false, sizeof(visited));
        bfs(u,v);

        if(!visited[v]) cout << 0 << "\n";
        else
        {
            vector<int> res;
            res.reserve(n+1);            
            while(v != u)
            {
                res.push_back(v);
                v = parent[v];
            }
            res.push_back(u);

            reverse(res.begin(), res.end());
            for(auto x : res) cout << x << " ";
            cout << "\n";
        } 
    }
    return 0;
}