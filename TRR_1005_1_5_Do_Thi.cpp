#include<bits/stdc++.h>
using namespace std;

int t,n,m;
int cnt[105];
vector<int> adj[105];

void chuyendscanhsangdske()
{
    for(int i= 1; i<= m; i++)
    {
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void in1()
{
    for(int i =1; i<= n; i++)
    {
        cout << adj[i].size() << " ";
    }
    cout << "\n";
}

void in2()
{
    cout << n << "\n";
    for(int i = 1; i<= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());

        cout << adj[i].size() << " ";
        for(auto x : adj[i])
        {
            cout << x << " ";
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
    if(t==1)
    {
        in1();
    }
    if(t==2)
    {
        in2();
    }
    return 0;
}