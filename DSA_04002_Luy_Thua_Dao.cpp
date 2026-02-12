#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

long long findMol(long long n, long long k)
{
    if(k == 1) return n%MOD;
    long long sum = findMol(n, k/2);
    sum = (sum*sum) % MOD;
    if(k % 2 == 1)
    {
        sum = (sum * n) % MOD;
    }
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        long long tmp = n;
        long long r = 0;
        while(n)
        {
            r = r*10 + n%10;
            n /= 10;
        }
        cout << findMol(tmp,r) << "\n";
    }
    return 0;
}
