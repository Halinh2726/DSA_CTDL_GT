#include<bits/stdc++.h>
using namespace std;

/*
1. Dung dfs + Backtracking

*/
int n,m,k;
vector<int> adj[10005];
int visited[10005];

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

bool check(int i, int c)
{
    for(auto x : adj[i])
    {
        if(visited[x] == c)
            return false;
    }
    return true;
}

bool dfs(int x)
{
    if(x > n)
        return true;
    for(int c = 1; c <= k; c++)
    {
        if(check(x,c))
        {
            visited[x] = c;
            if(dfs(x+1))
                return true;
            visited[x] = 0;
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
        cin >> n >> m >> k;
        for(int i = 1; i<= n; i++)
            adj[i].clear();
        memset(visited, false, sizeof(visited));
        chuyendscanhsangdske();

        if(dfs(1))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}