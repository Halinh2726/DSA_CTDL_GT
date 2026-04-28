#include <bits/stdc++.h>
using namespace std;

int n;
int a[105][105];
int num[105], low[105], parent[105];
bool visited[105];
bool check[105];
int tmp = 0;

void dfs(int u)
{
    visited[u] = true;
    num[u] = low[u] = ++tmp;
    int child = 0;

    for(int v = 1; v <= n; v++)
    {
        if(a[u][v])
        {
            if(!visited[v])
            {
                parent[v] = u;
                child++;
                dfs(v);

                low[u] = min(low[u], low[v]);

                // u không phải gốc
                if(parent[u] != 0 && low[v] >= num[u])
                    check[u] = true;
            }
            else if(v != parent[u])
            {
                low[u] = min(low[u], num[v]);
            }
        }
    }

    // u là gốc
    if(parent[u] == 0 && child > 1)
        check[u] = true;
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
            dfs(i);
    }

    vector<int> res;
    for(int i = 1; i <= n; i++)
    {
        if(check[i])
            res.push_back(i);
    }

    cout << res.size() << endl;
    if(res.size() > 0)
    {
        sort(res.begin(), res.end());
        for(int x : res)
            cout << x << " ";
    }

    return 0;
}