#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[1001];
bool visited[1001];

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int x : adj[v])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i= 1; i<= n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            int x; cin >> x;
            if(x == 1) adj[i].push_back(j);
        }
    }
    memset(visited, false, sizeof(visited));
    bfs(1);
    return 0;
}