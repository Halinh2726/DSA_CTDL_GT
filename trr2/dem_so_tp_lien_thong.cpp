#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001]; // Ma tran danh sach ke
bool visited[1001];

void dfs(int u)
{
    visited[u] = true;
    cout << u << " ";
    for(int x: adj[u])
    {
        if(!visited[x]) dfs(x);
    }
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    cout << u << " ";
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for(auto x : adj[tmp])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
void cnttplienthong()
{
    int ans = 0;
    memset(visited, false, sizeof(visited));

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            ans++;
            cout << "Cac thanh phan lien thong thu " << ans << ":\n";
            dfs(i);
            cout << "\n";
        }
    }

    cout << "So thanh phan lien thong: " << ans << "\n";
}


int main()
{
    cin >> n >> m;
    for(int i= 0; i< m; i++)
    {
        int x, y;
        cin >> x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cnttplienthong();
    return 0;
}