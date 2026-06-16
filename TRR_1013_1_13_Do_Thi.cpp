#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t;
    cin >> t;
    int n; cin >> n;
    int a[n+1][n+1];
    for(int i =1 ; i<= n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            cin >>a[i][j];
        }
    }
    
    if(t==1)
    {
        vector<int> degIn(n+1,0), degOut(n+1,0);
        for(int i = 1; i<= n;i++)
        {
            for(int j = 1;j <= n; j++)
            {
                if(a[i][j])
                {
                    degIn[j] += a[i][j];
                    degOut[i] += a[i][j];
                }
            }
        }

        for(int i =1; i<= n; i++)
        {
            cout << degIn[i] << " " << degOut[i] << "\n";
        }
    }

    if(t == 2)
    {
        vector<int> adj[n+1];
        for(int i= 1; i<= n; i++)
        {
            for(int j = 1; j<= n; j++)
            {
                if(a[i][j])
                    adj[i].push_back(j);
            }
        }

        cout << n <<"\n";
        for(int i = 1; i<= n; i++)
        {
            cout << adj[i].size() << " ";
            for(int x : adj[i])
                cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}