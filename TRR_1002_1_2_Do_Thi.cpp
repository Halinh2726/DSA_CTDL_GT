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
    cout << n << "\n";
    for(int i = 1; i<= n; i++)
    {
        vector<int> adj;
        for(int j = 1; j<= n; j++)
        {
            if(a[i][j] == 1)
                adj.push_back(j);
        }
        cout << adj.size();
        for(int x : adj)
        {
            cout << " " << x;
        }
        cout << "\n";
    }
}

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w" , stdout);
    cin >> t >> n;
    for(int i =1 ; i<= n;i++)
        for(int j = 1; j<= n; j++)
            cin >> a[i][j];
    if(t== 1)
        in1();
    if(t==2)
        in2();
    return 0;
}