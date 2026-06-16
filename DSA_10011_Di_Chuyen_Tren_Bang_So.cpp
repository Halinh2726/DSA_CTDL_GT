#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int, pair<int,int>>> adj[1005];
const int INF = 1e9;
int a[505][505];
int d[505][505];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void input()
{
    cin >> n >> m;
    
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< m;j++)
        {
            cin >> a[i][j];
        }
    }
}

void reset()
{
    for(int i = 0; i< n; i++)
        adj[i].clear();
}

void dijsktra()
{
    for(int i= 0; i< n; i++)
        for(int j= 0; j< m; j++)
            d[i][j] = INF;
    
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> q;
    d[0][0] = a[0][0];
    q.push({d[0][0], {0,0}});

    while(!q.empty())
    {
        auto top = q.top();
        q.pop();

        int chiphi = top.first;
        int u = top.second.first;
        int kc = top.second.second;

        if(chiphi > d[u][kc]) continue;

        for(int i = 0; i< 4; i++)
        {
            int nx = u + dx[i];
            int ny = kc + dy[i];
        

         if(nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if(d[nx][ny] > d[u][kc] + a[nx][ny])
                {
                    d[nx][ny] = d[u][kc] + a[nx][ny];

                    q.push({d[nx][ny], {nx, ny}});
                }
            }
        }
    }
     cout << d[n-1][m-1] << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        reset();
        input();
        dijsktra();
    }
    return 0;
}