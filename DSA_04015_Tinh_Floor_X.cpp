#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n,x;
        cin >> n >> x;
        vector<long long> a(n);
        long long ans = -1;
        for(int i =0;i< n; i++) cin >> a[i];
        long long l = 0, r = n-1;
        while(l<=r)
        {
            long long mid = l + (r-l) / 2;
            if(a[mid] <= x)
            {
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid -1;
            }
        }
        if(ans == -1)
        {
            cout << "-1\n";
        }
        else
        {
            cout << ans + 1 << "\n";
        }
    }
    return 0;
}