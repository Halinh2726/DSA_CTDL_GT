#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> adj[105];
int parent[105];
int sz[105];

struct Edge{
    int u,v,w;
};
vector<Edge> canh;

void input()
{
    canh.clear();
    cin >> n >> m;
    for(int i = 1; i<= m;i++)
    {
        int x,y,w;
        cin >> x >> y >> w;
        Edge e = Edge{x,y,w};
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

bool Union(int a,int b)
{
    a= findset(a);
    b = findset(b);
    if(a==b) return false;
    if(sz[a] < sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
    return true; 
}

bool cmp(Edge &a, Edge &b)
{
    if(a.w != b.w) return a.w < b.w;
    else if(a.u != b.u) return a.u < b.u;
    return a.v < b.v;
}

void krusal()
{
    int trongso = 0;
    vector<Edge> mst;
    sort(canh.begin(), canh.end(), cmp);
    for(int i = 0; i< m; i++)
    {
        if(mst.size() == n-1) break;
        Edge e = canh[i];
        if(Union(e.u, e.v))
        {
            mst.push_back(e);
            trongso += e.w;
        }
    }
    cout << trongso << "\n";
    for(auto x : mst)
    {
        cout << x.u << " " << x.v << " "<< x.w <<"\n";
    }
}

int main()
{
    freopen("CK.INP", "r",stdin);
    freopen("CK.OUT", "w", stdout);
    input();
    makeset();
    krusal();
    return 0;
}

