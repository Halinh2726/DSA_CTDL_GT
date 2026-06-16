#include<bits/stdc++.h>
using namespace std;


int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t;cin >> t;
    int n; cin >> n;

    vector<int> degIn(n+1,0), degOut(n+1,0);
    vector<int> res[n+1];
    for(int i = 1; i<= n; i++)
    {
        int k; cin >> k;
        while(k--)
        {
            int x; cin >> x;
            res[i].push_back(x);
            ++degOut[i];
            ++degIn[x];
        }
    }

    if(t == 1)
    {
        for(int i= 1; i<= n; i++)
        {
            cout << degIn[i] << " " << degOut[i] << "\n";
        }
    }

    if(t == 2)
    {
        vector<pair<int,int>> adj;
        for(int i = 1; i<= n; i++)
        {
            for(auto x : res[i])
            {              
                    adj.push_back({i,x});
            }
        }
        int sz = adj.size();
        vector<vector<int>> cd(n+1, vector<int>(sz+1,0));
        
        for(int i = 0; i < sz; i++)
        {
            int u = adj[i].first;
            int v = adj[i].second;

            cd[u][i] = 1;
            cd[v][i] = -1;
        }

        cout << n << " " << sz << "\n";
        for(int i= 1; i <= n; i++)
        {
            for(int j = 0; j< sz; j++)
                cout << cd[i][j] << " ";
            cout <<"\n";
        }
    }
}