#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> adj[10005];
bool visited[10005];
vector<pair<int, int>> caykhung;

void chuyendscanhsangdske()
{
    for(int i = 1; i<= m; i++)
    {
        int x,y;
        cin >> x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void reset()
{
    for(int i = 1; i<= n; i++)
    {
        adj[i].clear();
    }
    memset(visited, false, sizeof(visited));
    caykhung.clear();
}

void dfs(int i)
{
    visited[i] = true;

    for(auto x : adj[i])
    {
        if(!visited[x])
        {
            caykhung.push_back({i,x});
            dfs(x);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        reset();
        chuyendscanhsangdske();

        dfs(k);
        int ok = 0;
        for(int i = 1; i<= n; i++)
        {
            if(visited[i])
                ok++;
        }
        if(ok != n)
            cout << "-1\n";
        else
        {
            for(auto x : caykhung)
            {
                cout << x.first << " " << x.second << "\n";
            }
        }
    }
    return 0;
}