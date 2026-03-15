#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        vector<int> adj[1001];

        cin >> n >> m;
        for(int i= 0; i< m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        for(int i = 1; i<= n;i++)
        {
            cout << i << ": ";
            for(auto x : adj[i])
            {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}