#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> adj[10005];
int parent[10005];
int sz[10005];
struct edge{
    int x,y;
    int w;
};
vector<edge> canh;
void input()
{
    canh.clear();
    cin >> n >> m;
    for(int i = 1; i<= m; i++)
    {
        int x,y,w;
        cin >> x >>y >>w;
        edge e = edge{x,y,w};
        canh.push_back(e);
    }
}

void makeset()
{
    for(int i = 1; i<= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int findset(int a)
{
    if(parent[a] == a) return a;
    return parent[a] = findset(parent[a]);
}

bool Union(int a, int b)
{
    a =findset(a);
    b = findset(b);
    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

void krusal()
{
    // Tao cay khung cuc tieu rong
    vector<edge> mst;
    int d = 0;
    sort(canh.begin(), canh.end(), cmp);
    // Lap
    for(int i = 0; i < m; i++)
    {
        if(mst.size() == n - 1) break;
        edge e = canh[i];
        if(Union(e.x, e.y))
        {
            mst.push_back(e);
            d += e.w;
        }
    }
    cout << d << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        input();
        makeset();
        krusal();
    }
    return 0;
}