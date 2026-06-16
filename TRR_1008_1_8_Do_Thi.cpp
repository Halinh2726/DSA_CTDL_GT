#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT", "w", stdout);

    int t,n;
    cin >> t >> n;

    vector<int> adj[105];
    for(int i= 1; i<= n; i++)
    {
        int k;
        cin >> k;

        while(k--)
        {
            int x;
            cin >> x;
            
            adj[i].push_back(x);
        }
    }

    if(t==1)
    {
        for(int i = 1; i<= n; i++)
        {
            cout << adj[i].size() << " ";
        }
        cout << "\n";
    }

    else
    {
        vector<pair<int,int>> edges;

        for(int i = 1; i<= n; i++)
        {
            for(auto j : adj[i])
            {
                if(i < j)
                {
                    edges.push_back({i,j});
                }
            }
        }

        cout << n << " " << edges.size() << "\n";

        for(auto x: edges)
        {
            cout << x.first << " " << x.second << "\n";
        }
    }
    return 0;
}