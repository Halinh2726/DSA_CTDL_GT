#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1005];
int visited[1005];

void reset()
{
    for(int i = 1; i<= n; i++)
    {
        adj[i].clear();
    }
    memset(visited, 0, sizeof(visited));
}

void chuyendscanhsangdske()
{
    for(int i = 1; i<= m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

bool dfs(int i, int c)
{
    visited[i] = c;
    for(auto x : adj[i])
    {
        if(visited[x] == 0)
        {
            if(!dfs(x,3-c))
                return false;

        }
        else if(visited[x] == visited[i])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        reset();
        chuyendscanhsangdske();
        bool ok = true;

        for(int i = 1; i<= n; i++)
        {
            if(visited[i] == 0)
            {
                if(!dfs(i,1))
                {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}