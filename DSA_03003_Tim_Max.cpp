#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i< n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        long long sum = 0;
        for(int i= 0; i< n; i++)
        {
            sum = (sum + (a[i] * i)% MOD) % MOD;
        }
        cout << sum <<"\n";
    }
    return 0;
}