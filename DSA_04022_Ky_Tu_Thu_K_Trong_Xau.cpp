#include<bits/stdc++.h>
using namespace std;

int n,k;
int tmp[100];

char luythua(long long a, long long b)
{
    long long mid = pow(2,a-1);
    long long len = pow(2,a) -1;
    if(b == 1) return 'A';
    if(b == 2) return 'B';
    if(b == mid)
        return 'A' + a -1;
    else if(b < mid)
    {
        return luythua(a-1,b);
    }
    else if(b > mid)
        return luythua(a-1,b-mid);
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