#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<long long> c(n+m);

        for(int i = 0; i< n; i++) cin >> c[i];
        for(int i = n; i< n+m; i++) cin >> c[i];

        sort(c.begin(), c.end());

        for(long long x:c)
        {
            cout << x << " ";
        }
        cout <<"\n";
    }
    return 0;
}