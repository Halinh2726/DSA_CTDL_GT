#include<bits/stdc++.h>
using namespace std;

/*
- Goi f(i) la do dai day con tang dai nhat ket thuc o a(i), ta co cong thuc tinh: 
f(1) = 1;
f(i) = max(f{j} + 1); 1<= j < i va a(j) <a(i)
ket qua bai toan la max{f(i)}
Truy vet: yeu cau in ra mot cau hinh thoa man
*/

// Cach 1:
int main()
{
    int n; cin >> n;
    int a[n];
    for(int i = 1; i<= n; i++) cin >> a[i];
    vector<int> dp(n+1, 1);
    int ans = 1;
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j< i; j++)
        {
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}

// Cach 2: De quy 

int n;
vector<int> a;
vector<int> tmp;

int dequy(int i)
{
    if(tmp[i] != -1)
    {
        return tmp[i];
    }
    
    int b = 1;
    for(int j = 0; j< i; j++)
    {
        if(a[j] < a[i])
            b = max(b, dequy(j) + 1);
    }

    return tmp[i] = b;
}

int main()
{
    cin >> n;
    a.resize(n);
    tmp.assign(n, -1);

    for(int i = 0; i< n; i++)
        cin >> a[i];
    
    int ans = 1;
    for(int i = 0; i< n; i++)
    {
        ans = max(ans, dequy(i));
    }

    cout << ans << "\n";
    return 0;
}

// Cach 3: Dung mang tail[k] luu lai vi tri gia tri min co the cua day con tang co do dai k +1 + Binary Search

int main()
{
    int n; cin >> n;
    vector<int> dp(n+1, 1);
    vector<int> tail(n);
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int len = 0;
    for(int i =0; i< n; i++)
    {
        int l = 0, r = len - 1, pos = len;
        while(l <= r)
        {
            int mid = (l+r) / 2;
            if(tail[mid] >= a[i]){
                pos = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        // Tim thay va khong tim thay
        dp[i] = pos +1 ;
        tail[pos] = a[i];
        if(pos == len) len++;

    }
    cout << len << "\n";
}