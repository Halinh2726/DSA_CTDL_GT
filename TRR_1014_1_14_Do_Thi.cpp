#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t;
    cin >> t;
    int n;
    cin >> n;
    int a[n+1][n+1];
    for(int i= 1; i<= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    if(t==1)
    {
        vector<int> degIn(n+1,0), degOut(n+1,0);
        for(int i =1 ; i<= n; i++)
        {
            for(int j = 1; j<= n; j++)
            {
                if(a[i][j])
                {
                    degIn[j] += a[i][j];
                    degOut[i] += a[i][j];
                }
            }
        }

        for(int i = 1; i<= n; i++)
        {
            cout << degIn[i] << " " << degOut[i] << "\n";
        }
    }

    if(t==2)
    {
        vector<pair<int,int>> edges;
        for(int i= 1; i<= n; i++)
        {
            for(int j = 1; j <= n;j++)
            {
                if(a[i][j]) edges.push_back({i,j});
            }
        }

        int edge = edges.size();

        cout << n << " " << edge << "\n";
        
        vector<vector<int>> tmp(n+1, vector<int>(edge+1,0));
        for(int i = 0; i< edge; i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;

            tmp[u][i] = 1;
            tmp[v][i] = -1;
        }

        for(int i = 1; i<= n;i++)
        {
            for(int j = 0; j< edge; j++)
            {
                cout << tmp[i][j] << " ";
            }
            cout<< "\n";
        }
    }
    return 0;
}