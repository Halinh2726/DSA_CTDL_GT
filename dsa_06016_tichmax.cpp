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
        long long a[n], b[m];
        long long minx = LLONG_MAX;
        long long maxn = LLONG_MIN;
        for(int i =0; i<n; i++){
            long long x;
            cin >> x;
            maxn = max(maxn, x);
        }
        for(int i =0; i< m; i++){
            long long x;
            cin >> x;
            minx = min(minx, x);
        }

        cout << minx * maxn << "\n";
    }
    return 0;
}