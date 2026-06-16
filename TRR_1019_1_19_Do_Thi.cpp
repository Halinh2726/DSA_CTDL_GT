#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t;cin >> t;
    int n;cin >> n;
    vector<int> mtk[1005];
    vector<int> degIn(n+1,0), degOut(n+1,0);
    for(int i = 1; i<= n; i++)
    {
        int k; cin >> k;
        while(k--)
        {
            int x; cin >> x;
            mtk[i].push_back(x);
            ++degOut[i];
            ++degIn[x];
        }
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
        vector<pair<int,int>> adj;
        for(int i= 1; i<= n; i++)
        {
            for(auto x : mtk[i])
            {
                    adj.push_back({i,x});
            }
        }

        cout << n << " " << adj.size() << "\n";
        for(auto x : adj)
        {
            cout << x.first << " " << x.second << "\n";
        }
    }
    return 0;
}