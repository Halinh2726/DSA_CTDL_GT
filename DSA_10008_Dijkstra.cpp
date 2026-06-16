#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<pair<int,int>> adj[100005];

void input()
{
    cin >> n >> m >> k;
    for(int i = 1; i<= m; i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
}

void reset()
{
    for(int i = 1; i<= n;i++)
    {
        adj[i].clear();
    }
}

void dijikstra(int s)
{
    vector<int> d(n+1, 1e9);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,s});
    while(!q.empty())
    {
        pair<int,int> tp = q.top();q.pop();
        int u = tp.second;
        int kc = tp.first;
        if(kc > d[u]) continue;

        for(auto x : adj[u])
        {
            int v = x.first;
            int f = x.second;

            if(d[v] > d[u] + f)
            {
                d[v] = d[u] + f;
                q.push({d[v], v});
            }
        }
    }
    for(int i = 1; i<= n; i++)
    {
        cout << d[i] << " ";
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        reset();
        input();
        
        dijikstra(k);
        cout << "\n";
    }
    return 0;
}