#include<bits/stdc++.h>
using namespace std;

// Cong thuc lam tron len  (a + b - 1) / b
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,s,m;
        cin >> n >> s >> m;
        int so_ngay_toi_da = 0;
        long long total = s*m;
        int so_ngay_mua = s - (s/7);

        if(so_ngay_mua * n < total || m > n)
        {
            cout << "-1\n";
        }
        else
        {
            cout << (total + n - 1)/n <<"\n";
        }
    }
    return 0;
}