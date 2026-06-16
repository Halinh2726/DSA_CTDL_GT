#include<bits/stdc++.h>
using namespace std;

long long n,k;
long long a[100];

long long luythua(long long c, long long b)
{
    if(c == 1) return 0;
    if(c == 2) return 1;

    if(b <= a[c-2])
    {
        return luythua(c-2,b);
    }
    if(b > a[c-2])
    {
        return luythua(c-1,b-a[c-2]);
    }
}

int main()
{
    a[1] = 1;
    a[2] = 1;
    for(int i = 3; i< 93; i++)
    {
        a[i]= (a[i-1] + a[i-2]);
    }
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cout << luythua(n,k) << "\n";
    }
    return 0;
}