#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);    
    int t;
    cin >> t;
    int n,m; cin >> n >> m;
    vector<vector<int>> mtx(n+1, vector<int>(n+1));
    vector<int> degIn(n+1,0), degOut(n+1,0);
    for(int i = 1; i<= m; i++)
    {
        int x,y;
        cin >> x >> y;
        mtx[x][y] = 1;
        ++degIn[y];
        ++degOut[x];
    }

    if(t == 1)
    {
        for(int i =1; i<= n; i++)
        {
            cout << degIn[i] << " " << degOut[i] << "\n";
        }
    }

    if(t == 2)
    {
        cout << n << "\n";
        for(int i =1 ; i<= n; i++)
        {
            for(int j = 1; j<= n;j++)
            {
                cout << mtx[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}