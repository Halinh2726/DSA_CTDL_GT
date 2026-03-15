#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;cin >> n;
        long long dp[51];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i<= n; i++)
        {
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }
        cout << dp[n] << "\n";
    }
    return 0;
}