#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};

const int maxn = 1e5 + 5, oo = 1e9;
int n, m;
int dist[maxn], parent[maxn];
vector<Edge> graph;

void BellmanFord(int s)
{

    for (int v = 1; v <= n; ++v)
    {
        dist[v] = oo;
        parent[v] = 0;
    }

    dist[s] = 0;

    for (int i = 1; i < n; ++i)
    {
        for (Edge e : graph)
        {
            if (dist[e.u] != oo && dist[e.u] + e.w < dist[e.v])
            {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
            }
        }
    }

    for (Edge e : graph)
    {
        if (dist[e.u] != oo && dist[e.u] + e.w < dist[e.v])
        {
            cout << "Graph contains a negative weight cycle!";
            return;
        }
    }

    return;
}

int main()
{
    cin >> n >> m;

    graph.resize(m + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> graph[i].u >> graph[i].v >> graph[i].w;
    }

    BellmanFord(1);
}