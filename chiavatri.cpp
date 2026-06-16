#include<bits/stdc++.h>
using namespace std;

long long n,k;

long long luythua(long long a, long long b)
{
    long long mid = pow(2,a-1);
    long long len = pow(2,a) -1;
    if(b == mid)
        return a;
    else if(b < mid)
    {
        return luythua(a-1,b);
    }
    else if(b > mid)
        return luythua(a-1,b-1);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cout << luythua(n,k) << "\n";
    }
    return 0;
}