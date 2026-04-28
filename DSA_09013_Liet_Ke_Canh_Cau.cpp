#include<bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int n,m;
bool check[maxn];
int timeDfs = 0, bridge = 0;
int low[maxn], num[maxn];
vector<int> adj[maxn];

void dfs(int n, int pre)
{
    int con = 0;
    num[n] = low[n] = ++timeDfs;
    for(auto v : adj[n])
    {
        if(v != pre)
        {
            if(!num[v])
            {
                dfs(v,n);
                low[n] = min(low[n], low[v]);
                if(low[v] == num[v]) bridge++;
                con++;
                if(n == pre)
                {
                    if(con > 1) check[n] = true;
                }
                else if(low[v] >= num[n]) check[n] = true;
            }
            else
            {
                low[n] = min(low[n], num[v]);
            }
        }
    }
    // tail[n] = timeDfs;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i<= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i<= n; i++)
    {
        if(!num[i]) dfs(i,i);
    }
    int cnt = 0;
    for(int i = 1; i<= n; i++) cnt += check[i];
    cout << cnt << " " << bridge;
    return 0;
}