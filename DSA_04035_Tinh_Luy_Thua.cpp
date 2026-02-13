#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

long long power(long long a, long long b)
{
    if(b == 0) return 1;
    if(b == 1) return a % MOD;
    long long sum = power(a,b/2);
    sum = (sum * sum) % MOD;
    if(b % 2 == 1)
    {
        sum = (sum * (a%MOD)) % MOD;
    }
    return sum;
}
int main()
{
    long long a,b;
    
    while(cin >> a >> b)
    {
        if(a== 0 && b == 0) break;
        cout << power(a%MOD,b) << "\n";
    }
    return 0;
}