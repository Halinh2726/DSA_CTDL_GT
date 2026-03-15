#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i< n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        long long min_x = LLONG_MAX;
        for(int i = 1; i< n; i++)
        {
            long long tmp = a[i] - a[i-1];
            if(tmp < min_x)
            {
                min_x = tmp;
            }
        }
        cout << min_x << "\n";
    }
    return 0;
}