#include<bits/stdc++.h>
using namespace std;

int n,m;
int parent[1005];
int sz[1005];

void makeset(int n)
{
    for(int i = 1; i<= n;i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v)
{
    if(v == parent[v])
    {
        return v;
    }
    return parent[v] = find(parent[v]);
}

int unions(int a,int b)
{
    a = find(a); b = find(b);
    if(a != b)
    {
        if(sz[a] < sz[b])
        {
            swap(a,b);
        }
    }
    else 
        return 1;
    parent[b] = a;
    sz[a] += sz[b];
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        makeset(n);

        bool cycle = false;
        for(int i= 0; i<m; i++)
        {
            int x,y;
            cin >> x >> y;
            if(unions(x,y))
            {
                cycle = true;
            }
        }

        if(cycle) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
