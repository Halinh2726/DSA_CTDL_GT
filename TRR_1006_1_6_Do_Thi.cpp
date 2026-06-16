#include<bits/stdc++.h>
using namespace std;

int t,n,m;
int a[105][105];
int cnt[105];
vector<int> adj1[105];
vector<pair<int,int>> edges;

void chuyendscanhsangdske()
{
    for(int i = 1; i<= m; i++)
    {
        int x,y;
        cin >> x >> y;

        edges.push_back({x,y});
        adj1[x].push_back(y);
        adj1[y].push_back(x);
    }
}

void in1()
{
    for(int i = 1; i<= n; i++)
    {
        cout << adj1[i].size() << " ";
    }
    cout << "\n";
}

void in2()
{
    cout << n <<  " " << m << "\n";

    vector<vector<int>> mtx(n+1, vector<int>(m+1,0));
    for(int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        mtx[u][i] = 1;
        mtx[v][i] = 1;
    }

    for(int i = 1; i<= n; i++)
    {
        for(int j = 0; j< m;j++)
        {
            cout << mtx[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t >> n >> m;
    chuyendscanhsangdske();
    if(t == 1)
    {
        in1();
    }
    if(t==2)
    {
        in2();
    }
    return 0;
}