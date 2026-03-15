#include<bits/stdc++.h>
using namespace std;

/*
Dùng kĩ thuật three - pointers
Đặt i = 0, j = 0, k = 0

So sánh A[i], B[j], C[k]

Nếu 3 giá trị bằng nhau → đó là phần tử chung → in ra và tăng cả 3 con trỏ.

Nếu không bằng nhau → tăng con trỏ của phần tử nhỏ nhất.

Lặp đến khi một trong ba con trỏ chạm cuối mảng.
*/
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        vector<long long> a(n), b(m), c(k);
        for(int i = 0; i< n; i++) cin >> a[i];
        for(int i= 0; i<m; i++) cin >> b[i];
        for(int i = 0; i< k; i++) cin >> c[i];

        int i = 0, j= 0, l = 0;
        int check = 0;
        while(i < n && j < m && l < k)
        {
            if(a[i] == b[j] && a[i] == c[l])
            {
                cout << a[i] << " ";
                check = 1;
                i++; j++; l++;
            }
            else
            {
                long long minx = min({a[i], b[j], c[l]});
                if(a[i] == minx) i++;
                if(b[j] == minx) j++;
                if(c[l] == minx) l++;
            }
        }
        if(!check) cout << "NO";
        cout <<"\n";
    }
    return 0;
}