#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t;
    cin >> t;
    int n; cin >> n;
    vector<int> degIn(n+1,0), degOut(n+1, 0);
    vector<vector<int>> res(n+1, vector<int>(n+1,0));

    for(int i = 1; i<= n; i++)
    {
        int k; cin >> k;
        degOut[i] += k;
        while(k--)
        {
            int x; cin >> x;
            ++degIn[x];
            res[i][x] = 1;
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
        cout << n << "\n";
        for(int i = 1; i<= n; i++)
        {
            for(int j = 1; j<= n; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}