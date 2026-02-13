#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n,k;
        cin >> n >> k;
        vector<long long> a(n);
        for(int i = 0; i< n; i++) cin >> a[i];
        auto it = lower_bound(a.begin(), a.end(), k);

        if(it != a.end() && *it == k)
        {
            cout << (it - a.begin()) + 1 <<"\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}