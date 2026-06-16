#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
bool visited[1001];

void chuyendscanhsangdske()
{
    for(int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void reset()
{
    for(int i = 1; i<= n; i++)
    {
        adj[i].clear();
    }
}

bool dfs(int i, int par)
{
    visited[i] = true;
    for(auto x: adj[i])
    {
        if(!visited[x])
        {
            if(dfs(x,i))
                return true;
        }
        else if(x != par)
        {
            return true;
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
        int ok = 0;
        cin >> n >> m;
        // memset(visited, false, sizeof(visited));
        reset();
        chuyendscanhsangdske();
        for(int i = 1; i<= n; i++)
        {
            if(!visited[i])
            {
                if(dfs(i,0))
                {
                    ok = 1;
                    break;
                }
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}