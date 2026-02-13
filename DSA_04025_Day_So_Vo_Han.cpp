#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

struct Matrix
{
    long long a[2][2];
};

Matrix matran(Matrix x, Matrix y)
{
    Matrix result;
    for(int i = 0; i< 2; i++)
    {
        for(int j = 0; j< 2; j++)
        {
            result.a[i][j] = 0;
            for(int k = 0; k< 2; k++)
            {
                result.a[i][j] = (result.a[i][j] + x.a[i][k] * y.a[k][j] % MOD) % MOD;
            }
        }
    }
    return result;
}

Matrix luy_thua(Matrix base, long long n)
{
    if(n == 1)
    {
        return base;
    }
    Matrix matran_sum = luy_thua(base, n/2);
    Matrix result = matran(matran_sum, matran_sum);

    if(n%2 == 1)
    {
        result = matran(result, base);
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;

        if(n== 0)
        {
            cout << 0 <<"\n";
            continue;
        }       
        Matrix base;
        base.a[0][0] = 1;
        base.a[0][1] = 1;
        base.a[1][0] = 1;
        base.a[1][1] = 0;

        Matrix result = luy_thua(base, n);
        cout << result.a[0][1] << "\n";
    }
    return 0;
}