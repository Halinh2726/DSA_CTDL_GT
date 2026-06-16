#include<bits/stdc++.h>
using namespace std;

int n;
int arr[105][105];
vector<int> adj[105];
bool visited[105];
vector<int> unadj[105];

void dfs(int u, vector<int> x[])
{
    visited[u] = true;
    for(int v : x[u])
    {
        if(!visited[v])
        {
            dfs(v,x);
        }
    }
}

bool scc()
{
    for(int i = 1; i<= n;i++)
    {
        memset(visited, false, sizeof(visited));
        dfs(i,adj);
        for(int j = 1; j <= n; j++)
        {
            if(!visited[j]) return false;
        }
    }
    return true;
}

bool unscc()
{
    memset(visited, false, sizeof(visited));
    dfs(1,unadj);
    for(int i = 1; i<= n ; i++)
    {
        if(!visited[i]) return false;
    }
    return true;
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >>  n;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n;j++)
        {
            cin >>arr[i][j];
            if(arr[i][j])
            {
                adj[i].push_back(j);

                unadj[i].push_back(j);
                unadj[j].push_back(i);
            }
        }
    }

    if(scc()) cout << 1 << "\n";
    else if(unscc()) cout << 2 << "\n";
    else cout << 0 << "\n";

    return 0;
}