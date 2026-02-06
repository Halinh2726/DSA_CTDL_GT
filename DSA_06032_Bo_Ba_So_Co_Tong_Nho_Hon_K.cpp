#include<bits/stdc++.h>
using namespace std;

long long n, k;
vector<long long> a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        a.resize(n);
        for(int i = 0; i<n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        long long cnt = 0;
        for(int i = 0; i< n-2; i++)
        {
            long long l = i+1, r = n-1;
            while(l < r)
            {
                long long sum = 1ll * a[l] + a[r] + a[i];
                if(sum < k)
                {
                    cnt += (r-l);
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        cout << cnt <<"\n";
    }
    return 0;
}