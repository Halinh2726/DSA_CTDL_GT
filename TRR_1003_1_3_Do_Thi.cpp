#include<bits/stdc++.h>
using namespace std;

int t,n;
int a[105][105];
int cnt[105];

void in1()
{
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            if(a[i][j] == 1)
                cnt[i] += a[i][j];
        }
    }
    
    for(int i = 1; i<= n; i++)
    {
        cout << cnt[i] << " ";
    }
    cout << "\n";
}

void in2()
{
    vector<pair<int,int>> adj;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(a[i][j])
                adj.push_back({i,j});
        }
    }

    int tmp = adj.size();
    cout << n << " " << tmp << endl;
    vector<vector<int>> inc(n + 1, vector<int>(tmp + 1, 0));

        for (int i = 0; i < tmp; ++i) {
               int u = adj[i].first;
            int v = adj[i].second;

            inc[u][i] = 1;
            inc[v][i] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < tmp; ++j) {
                cout << inc[i][j] << " ";
            }
            cout << endl;
        }
}

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t >> n;
    for(int i = 1; i<= n; i++)
        for(int j = 1; j<= n; j++)
            cin >> a[i][j];
    if(t==1)
        in1();
    if(t==2)
        in2();
    return 0;
}

