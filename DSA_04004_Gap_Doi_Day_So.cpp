//AN​=AN−1​,N,AN−1​
#include<bits/stdc++.h>
using namespace std;

long long power(long long a, long long b)
{
    if(b==0) return 1;
    if(b==1) return a;
    long long sum = power(a,b/2);
    sum = (sum*sum);
    if(b%2 == 1)
    {
        sum = (sum*a);
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n,k;
        cin >> n >> k;
        

        while(n)
        {
            long long mid = power(2,n-1);
            if(k == mid)
            {
                cout << n <<"\n";
                break;
            }
            else if(k < mid)
            {
                n = n-1;
            }
            else if(k >  mid)
            {
                n = n-1;
                k = k- mid;
            }
        }
    }
    return 0;
}