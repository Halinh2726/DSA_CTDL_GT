#include<bits/stdc++.h>
using namespace std;

int t,m,n;
int a[105][105];
vector<int> adj[105];
int cnt[105];

void chuyendscanhsangdske()
{
    cin >> t;
    cin >> n >> m;
    int tmp[105][105];
    for(int i = 1; i<= m; i++)
    {
        int x,y;
        cin >> x >>y;
        
        a[x][y] = 1;
        a[y][x] = 1;
    }
}
void in1()
{
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            // if(a[i][j])
                cnt[i] += a[i][j];
        }
    }

    for(int i= 1; i<= n; i++)
    {
        cout << cnt[i] << " ";
    }
    cout << "\n";
}

void in2()
{
    cout << n << "\n";
    for(int i = 1; i<= n;i++)
    {
        for(int j = 1; j<= n; j++)
        {
            cout << a[i][j];
            if(j  < n) cout << " ";
        }
        cout << "\n";
    }
}
int main()
{
    freopen("DT.INP", "r",stdin);
    freopen("DT.OUT","w", stdout);
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    chuyendscanhsangdske();
    if(t==1)
    {
        in1();
    }
    if(t==2)
    {
        in2();
    }
    return 0;
}