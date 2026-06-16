#include<bits/stdc++.h>
using namespace std;

int n;
int arr[105][105];
vector<pair<int,int>> adj;
vector<int> dsk[105];
bool visited[105];

void dfs(int u, int start, int end)
{
    visited[u] = true;

    for(int x : dsk[u])
    {
        if((x == start && u == end) || (x == end && u == start )) continue;
        if(!visited[x])
        {
            dfs(x, start, end);
            visited[x] = true;
        }
    }
}

int cnt_lt(int u, int v)
{
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for(int i = 1; i<=n; i++)
    {
        if(!visited[i])
        {
            ++cnt;
            dfs(i,u,v);
        }
    }
    return cnt;
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);  
    cin >> n;
    for(int i = 1; i<= n;i++)
    {
        for(int j = 1; j<= n;j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i<= n; i++)
    {
        for(int j = i+1; j <= n;j++)
        {
            if(arr[i][j])
            {
                adj.push_back({i,j});
                dsk[i].push_back(j);
                dsk[j].push_back(i);
            }
        }
    }

    vector<pair<int,int>> bridges;
    int tmp = cnt_lt(-1,-1);

    for(pair<int,int> x : adj)
    {
        int tmp1 = cnt_lt(x.first, x.second);
        
        if(tmp1 > tmp)
        {
            bridges.push_back({x.first, x.second});
        }
    }

    cout << bridges.size() << "\n";
    for(pair<int,int> x : bridges)
    {
        cout << x.first << " " << x.second <<"\n";
    }
    return 0;
}