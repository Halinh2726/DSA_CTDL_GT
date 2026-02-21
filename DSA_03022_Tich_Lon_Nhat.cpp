#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i< n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    long long maxn = LLONG_MIN;

    // 2 phan tu
    maxn = max(maxn, 1LL * a[0] * a[1]);
    maxn = max(maxn, 1LL * a[n-1] * a[n-2]);

    // 3 phan tu
    maxn = max(maxn, 1LL * a[0] * a[1] * a[n-1]);
    maxn = max(maxn, 1LL * a[n-1] * a[n-2] * a[n-3]);

    cout << maxn <<"\n";
    return 0;
}