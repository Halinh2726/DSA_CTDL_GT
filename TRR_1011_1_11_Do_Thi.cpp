#include<bits/stdc++.h>
using namespace std;

struct Edges{
    int x,y,weight;
};

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t;
    cin >> t;
    int n,m; cin >> n >> m;
    vector<Edges> Edge;
    for(int i = 1; i<= m; i++)
    {
        Edges u;
        cin >> u.x >> u.y >> u.weight;

        Edge.push_back(u);
    }

    if(t==1)
    {
        vector<int> tmp(n+1,0);
        for(Edges u : Edge)
        {
            ++tmp[u.x];
            ++tmp[u.y];
        }
        for(int i= 1; i<= n; i++) cout << tmp[i] << " ";
        cout << "\n";
    }

    if(t==2)
    {
        vector<vector<int>> mtx(n+1, vector<int>(n+1, 10000));

        for(Edges u : Edge)
        {
            mtx[u.x][u.y] = u.weight;
            mtx[u.y][u.x] = u.weight;
        }

        for(int i = 1; i <= n; i++)
            mtx[i][i] = 0;
        cout << n << "\n";
        for(int i = 1; i<= n; i++)
        {
            for(int j = 1; j<= n; j++)
            {
                cout << mtx[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}