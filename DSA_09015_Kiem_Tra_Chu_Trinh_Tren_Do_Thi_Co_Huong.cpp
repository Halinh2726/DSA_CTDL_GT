#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
int visited[1001];

void chuyendscanhsangdske()
{
    for(int i = 0; i< m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

void reset()
{
    for(int i = 0; i< n; i++)
    {
        adj[i].clear();
    }
    memset(visited, false, sizeof(visited));
}

bool dfs(int i)
{
    visited[i] = 1;
    for(auto x: adj[i])
    {
        if(visited[x] == 0)
        {
            if(dfs(x))
                return true;
        }
        else if(visited[x] == 1)
        {
            return true;
        }
    }
    visited[i] = 2;
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
            if(visited[i] == 0)
            {
                if(dfs(i))
                {
                    ok = 1;
                    break;
                }
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
        cout << "\n";
    }
    return 0;
}