#include<bits/stdc++.h>
using namespace std;
const long long MOD = 123456789;
// Số cách cho biết có bao nhiêu dãy số nguyên dương có tổng các phần tử trong dãy bằng n là 2^(n-1)

long long power(long long a, long long b)
{
    if(b == 0) return 1;
    if(b == 1) return a % MOD;
    long long sum = power(a, b/2);
    sum = (sum*sum) % MOD;
    if(b % 2 == 1)
    {
        sum = (sum*a) % MOD;
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
        cout << power(2, n-1) << "\n";
    }
    return 0;
}