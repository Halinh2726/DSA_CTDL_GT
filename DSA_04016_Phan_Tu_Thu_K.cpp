#include<bits/stdc++.h>
using namespace std;

void merge(vector<long long> a, vector<long long> b,vector<long long>& c, int n, int m)
{
    int i = 0, j = 0;
    while(i < n && j < m)
    {
        if(a[i] <= b[j])
        {
            c.push_back(a[i]);
            i++;
        }
        else
        {
            c.push_back(b[j]);
            j++;
        }
    }

    while(i < n)
    {
        c.push_back(a[i]);
        i++;
    }
    while(j < m)
    {
        c.push_back(b[j]);
        j++;
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long m,n,k;
        cin >> m >> n >> k;
        vector<long long> a(m);
        vector<long long> b(n);
        vector<long long> c;
        for(int i= 0; i< m; i++) cin >> a[i];
        for(int i = 0; i< n; i++) cin >> b[i];

        merge(a,b,c,m,n);
        cout << c[k-1] << "\n";
        // long long l = 0, r =n-1;
        // long long ans = -1;
        // while(l <= r)
        // {
        //     long long mid = l + (r-l) / 2;
        //     if(mid <= k)
        //     {
        //         ans  = c[mid];
        //         r  = mid - 1;
        //     }
        //     else if(mid >= k)
        //     {
        //         l = mid + 1;
        //     }
        // }

        // cout << ans <<"\n";
    }
    return 0;
}