#include<bits/stdc++.h>
using namespace std;

int n;
int arr[105][105];
bool visited[105];
vector<int> dsk[105];
vector<pair<int,int>> adj, bridges;

void bfs(int u, int start, int stop)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty())
    {
        int x = q.front(); q.pop();

        for(int v : dsk[x])
        {
            if((v == start && x == stop) || (v == stop && x == start)) continue;
            if(!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int cnt_lt(int u, int v)
{
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for(int i = 1; i<= n; i++)
    {
        if(!visited[i])
        {
            bfs(i,u,v);
            ++cnt;
            //visited[i] = true;
        }
    }
    return cnt;
}


int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);  
    cin >> n;
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i<= n; i++)
    {
        for(int j = i+1; j<= n; j++)
        {
            if(arr[i][j])
            {
                adj.push_back({i,j});
                dsk[i].push_back(j);
                dsk[j].push_back(i);
            }
        }
    }

    int tmp = cnt_lt(-1,-1);
    for(auto x : adj)
    {
        int cnt = cnt_lt(x.first, x.second);
        if(cnt > tmp)
        {
            bridges.push_back({x.first, x.second});
        }
    }

    cout << bridges.size() << "\n";
    for(auto x : bridges)
    {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}