#include<bits/stdc++.h>
using namespace std;

int n, m;
int parent[200005];
int sz[200005];

struct edge
{
    int x, y,z;
};

vector<edge> canh;

void makeset(int n)
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int findset(int v)
{
    if(v == parent[v])
    {
        return v;
    }
    return parent[v] = findset(parent[v]);
}

bool unions(int a, int b)
{
    a = findset(a);
    b = findset(b);

    if(a == b)
    {
        return false;
    }

    if(sz[a] < sz[b])
    {
        swap(a, b);
    }

    parent[b] = a;
    sz[a] += sz[b];

    return true;
}

bool cmp(edge a, edge b)
{
    return a.z < b.z;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        canh.clear();

        makeset(n);

        for(int i = 1; i <= m; i++)
        {
            edge e;
            cin >> e.x >> e.y >> e.z;
            canh.push_back(e);
        }

        sort(canh.begin(), canh.end(), cmp);

        long long mst = 0;

        for(edge e : canh)
        {
            if(unions(e.x, e.y))
            {
                mst += e.z;
            }
        }

        cout << mst << '\n';
    }

    return 0;
}