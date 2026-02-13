#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long n;

struct Matran
{
    long long a[20][20];
};

Matran matrix(Matran a, Matran b)
{
    Matran result;
    for(int i = 0; i< 20; i++)
    {
        for(int j = 0; j< 20; j++)
        {
            result.a[i][j] = 0;
            for(int k = 0; k< n; k++)
            {
                result.a[i][j] = (result.a[i][j] + a.a[i][k] * b.a[k][j] % MOD) % MOD;
            }           
        }
    }
    return result;
}

Matran luy_thua(Matran x, long long n)
{
    if(n== 1) return x;
    Matran sum = luy_thua(x, n/2);
    Matran mt_sum = matrix(sum, sum);

    if(n%2 == 1)
    {
        mt_sum = matrix(x,mt_sum);
    }
    return mt_sum;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long k;
        cin >> n >> k;
        Matran a;
        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j< n; j++)
            {
                cin >> a.a[i][j];
            }
        }

        Matran result = luy_thua(a,k);

        // for(int i = 0; i< n; i++)
        // {
        //     for(int j = 0; j< n; j++)
        //     {
        //         cout << result.a[i][j] << " ";
        //     }
        //     cout <<"\n";
        // }

        long long sum = 0;
        for(int i = 0; i< n; i++)
        {
            sum = (sum + result.a[i][n-1]) % MOD;
        }
        cout << sum <<"\n";
    }
    return 0;
}


