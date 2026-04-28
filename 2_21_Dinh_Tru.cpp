#include<bits/stdc++.h>
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
    num[u]= low[u] = ++tmp;
    int child = 0;

    for(int i = 1; i<= n; i++)
    {
        if(a[u][i])
        {
            if(!visited[i])
            {
                parent[i] = u;
                child++;
                dfs(i);

                low[u] = min(low[u], low[i]);

                if(parent[u] != 0 && low[i] >= num[u])
                    check[u] = true;
            }
            else if(i != parent[u])
            {
                low[u] = min(low[u], num[i]);
            }
        }
    }
    if(parent[u] == 0 && child > 1)
    {
        check[u] = true;
    }
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= n; j++)
            cin >> a[i][j];
    }

    for(int i = 1; i<= n; i++)
    {
        if(!visited[i])
            dfs(i);
    }

    vector<int> res;
    for(int i = 1; i<= n; i++)
    {
        if(check[i])
            res.push_back(i);
    }

    cout << res.size() << "\n";
    if(res.size() > 0)
    {
        sort(res.begin(), res.end());
        for(int x : res)
        {
            cout << x << " ";
        }
    }
    return 0;
}