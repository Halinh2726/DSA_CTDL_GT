#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);   
    int t;
    cin >> t;
    int n,m;
    cin >> n >> m;

    vector<int> adj[1005];
    vector<int> degIn(n+1,0), degOut(n+1,0);

    for(int i = 1; i<= m; i++)
    {
        int x,y;
        cin >> x >> y;
        ++degIn[y]; 
        ++degOut[x];
        adj[x].push_back(y);
    }

    if(t==1)
    {
        for(int i = 1; i<= n;i++)
        {
            cout << degIn[i] << " " << degOut[i] << "\n";
        }
    }

    if(t==2)
    {
        cout << n << "\n";
        for(int i = 1; i<= n;i++)
        {
            cout << adj[i].size() << " ";
            for(auto x : adj[i])
            {
                cout << x << " ";
            }
            cout <<"\n";
        }
    }
    return 0;
}