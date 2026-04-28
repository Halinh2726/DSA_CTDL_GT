#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main()
{
    int n, s;
    if(!(cin >> n >> s)) return 0;

    vector<tuple<int,int,long long>> edge;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            long long w;
            cin >> w;
            if(i != j && w != 0)
                edge.push_back({i,j,w});
        }
    }

    vector<long long> dist(n+1, INF);
    vector<int> parent(n+1, -1);

    dist[s] = 0;
    parent[s] = s;

    for(int i = 1; i <= n-1; i++)
    {
        for(auto &e : edge)
        {
            int u, v;
            long long w;
            tie(u,v,w) = e;

            if(dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // check negative cycle
    for(auto &e : edge)
    {
        int u, v;
        long long w;
        tie(u,v,w) = e;

        if(dist[u] != INF && dist[u] + w < dist[v])
        {
            cout << "Do thi co chu trinh am";
            return 0;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << "K/c " << s << " -> " << i << " = ";

        if(dist[i] == INF)
        {
            cout << "INF;\n\n";
            continue;
        }

        cout << dist[i] << "; ";

        vector<int> path;
        int v = i;
        while(v != s)
        {
            path.push_back(v);
            v = parent[v];
        }
        path.push_back(s);

        for(int k = 0; k < path.size(); k++)
        {
            if(k == 0) cout << path[k];
            else cout << " <- " << path[k];
        }

        cout << "\n\n";
    }

    return 0;
}