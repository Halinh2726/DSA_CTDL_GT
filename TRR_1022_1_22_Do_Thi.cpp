#include<bits/stdc++.h>
using namespace std;

struct edges{
    int u,v,weight;
};

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t;cin >> t;
    int n,m; cin >> n >> m;
    vector<int> degIn(n+1,0), degOut(n+1,0);
    vector<edges> res;
    for(int i = 1; i<= m; i++)
    {
        edges x;
        cin >> x.u >> x.v >> x.weight;
        res.push_back(x);
        ++degOut[x.u];
        ++degIn[x.v];
    }

    if(t==1)
    {
        for(int i = 1; i<= n; i++)
        {
            cout << degIn[i] << " " << degOut[i] << "\n";
        }
    }

    if(t==2)
    {
        cout << n <<  "\n";
        vector<vector<int>> tmp(n+1,vector<int>(n+1,10000));

        for(edges x: res)
        {
            tmp[x.u][x.v] = x.weight;
        }

        for(int i = 1; i<= n; i++)
        {
            tmp[i][i] = 0;
            for(int j = 1; j<= n;++j)
                cout << tmp[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}