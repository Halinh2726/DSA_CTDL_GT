#include<bits/stdc++.h>
using namespace std;

const int MAXV = 1001;

int V, E, S, T;
vector<int> adj[MAXV];
bool visited[MAXV];
int parent[MAXV];

void chuyen_dscanh_dske()
{
    cin >> V >> E >> S >> T;
    for(int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

bool bfs(int s, int t)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        if(u == t) return true;

        for(int x : adj[u])
        {
            if(!visited[x])
            {
                visited[x] = true;
                parent[x] = u;
                q.push(x);
            }
        }
    }
    return false;
}

void reset()
{
    for(int i = 0; i < MAXV; i++)
    {
        adj[i].clear();
        visited[i] = false;
        parent[i] = -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(parent, parent + MAXV, -1);

    int tc;
    cin >> tc;
    while(tc--)
    {
        chuyen_dscanh_dske();

        if(bfs(S, T))
        {
            vector<int> path;
            for(int v = T; v != -1; v = parent[v])
                path.push_back(v);

            reverse(path.begin(), path.end());
            for(int i = 0; i < (int)path.size(); i++)
            {
                if(i > 0) cout << " ";
                cout << path[i];
            }
            cout << "\n";
        }
        else
        {
            cout << "-1\n";
        }
        reset();
    }
    return 0;
}