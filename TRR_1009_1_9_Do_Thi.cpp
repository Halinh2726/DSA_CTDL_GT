#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int n; cin >> n;
    vector<int> degOut(n+1,0);

    vector<int> adj[n+1];
    for(int i = 1; i<= n ; i++)
    {
        int k; cin >> k;
        while(k--)
        {
            int x;
            cin >> x;
            ++degOut[i];
            adj[i].push_back(x);
        }
    }

    if(t==1)
    {
        for(int i = 1; i<= n; i++)
            cout << degOut[i] << " ";
        cout << "\n";
    }

    if(t==2)
    {
        vector<pair<int,int>> res;

        for(int i = 1; i<= n; i++)
        {
            for(auto x : adj[i])
            {
                if(i < x)
                    res.push_back({i,x});
            }
        }

        int sz = res.size();
        vector<vector<int>> tmp(n+1, vector<int>(sz+1,0));
        for(int i = 0; i< sz; i++)
        {
            int u = res[i].first;
            int v = res[i].second;

            tmp[u][i] = 1;
            tmp[v][i] = 1;
        }

        cout << n << " " << sz << "\n";
        for(int i = 1; i<= n; i++)
        {
            for(int j = 0; j < sz; j++)
            {
                cout << tmp[i][j] << " ";
            }
            cout << "\n"; 
        }
    }
    return 0;
}