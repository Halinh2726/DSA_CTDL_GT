#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[10005];
int visited[10005];

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
}

bool dfs(int i, int cnt)
{
    if(cnt == n)
    {
        return true;
    }

    for(auto x : adj[i])
    {
        if(!visited[x])
        {
            visited[x] = true;

            if(dfs(x, cnt+1))
                return true;
            
            visited[x] = false;
        }
    }
    return false;
}

bool hamilton()
{
    for(int i = 1; i<= n; i++)
    {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        if(dfs(i,1))
            return true;
    }
    return false;
}

int main()
{
    int t; cin >>t;
    while(t--)
    {
        cin >> n >> m;
        reset();
        chuyendscanhsangdske();
        if(hamilton())
            cout << "1\n";
        else    cout << "0\n";
    }
    return 0;
}
