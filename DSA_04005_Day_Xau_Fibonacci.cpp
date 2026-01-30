#include<bits/stdc++.h>
using namespace std;

long long a[100];

char fibo(long long n, long long i)
{
    if(n==1) return 'A';
    if(n==2) return 'B';

    if(i <= a[n-2])
    {
        return fibo(n-2,i);
    }
    else{
        return fibo(n-1, i - a[n-2]);
    }
}

int main()
{
    a[1] = a[2] = 1;
    for(int i = 3; i <= 92; i++)
        a[i] = a[i-1] + a[i-2];
    int t;
    cin >> t;
    while(t--)
    {
        long long n,k;
        cin >> n >> k;
        cout  << fibo(n,k) << "\n";
    }
    return 0;
}