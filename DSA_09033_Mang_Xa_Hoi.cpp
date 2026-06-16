#include<bits/stdc++.h>
using namespace std;

int n, m;
int parent[100005];
int sz[100005];
int edge[100005];

void makeset()
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
        edge[i] = 0;
    }
}

int findset(int u)
{
    if(u == parent[u])
        return u;
    return parent[u] = findset(parent[u]);
}

void unions(int a, int b)
{
    a = findset(a);
    b = findset(b);

    if(a != b)
    {
        if(sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;

        sz[a] += sz[b];
        edge[a] += edge[b];
    }

    edge[findset(a)]++;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        makeset();

        for(int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;

            unions(x, y);
        }

        bool ok = true;

        for(int i = 1; i <= n; i++)
        {
            if(parent[i] == i)
            {
                int tmp = sz[i];
                int canh = edge[i];

                if(canh != tmp * (tmp - 1) / 2)
                {
                    ok = false;
                    break;
                }
            }
        }

        if(ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}