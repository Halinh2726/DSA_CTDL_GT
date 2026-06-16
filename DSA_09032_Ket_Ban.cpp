#include<bits/stdc++.h>
using namespace std;

int n,m;
int parent[200005];
int sz[200005];

struct edge
{
    int x,y;
};

vector<edge> ed;

void make_set(int n)
{
    for(int i = 1; i<=n; i++)
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

    if(a==b)
    {
        return false;
    }
    if(sz[a] <sz[b])
        swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];

    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        make_set(n);

        for(int i = 1; i<= m; i++)
        {
            int x,y;
            cin >> x >> y;

            unions(x,y);
        }

        int cnt = 0;
        for(int i = 1; i<= n; i++)
        {
            cnt = max(cnt, sz[findset(i)]);
        }
        cout << cnt <<"\n";
    }
    return 0;
}