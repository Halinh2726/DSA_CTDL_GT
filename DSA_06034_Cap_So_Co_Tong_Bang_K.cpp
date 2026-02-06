#include<bits/stdc++.h>
using namespace std;

long long n,k;
vector<long long> a;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        a.resize(n);
        for(int i = 0; i< n; i++) cin >> a[i];
        long long cnt = 0;
        sort(a.begin(), a.end());
        int l = 0, r = n-1;
        while(l < r)
        {
            long long sum = a[l] + a[r];
            if(sum < k)
            {
                l++;
            }
            else if (sum > k)
            {
                r--;
            }
            else
            {
                if (a[l] == a[r]) {
                    long long m = r - l + 1;
                    cnt += m * (m - 1) / 2;
                    break;
                }
                // l++;
                // r--;
                else
                {
                    long long cntl = 1, cntr = 1;
                    while( l+1< r && a[l] == a[l+1])
                    {
                        cntl++;
                        l++;
                    }
                    while(r-1 > l && a[r] == a[r-1])
                    {
                        cntr++;
                        r--;
                    }

                    cnt += cntl * cntr;
                    l++;
                    r--;
                }
            }
        }
        cout << cnt <<"\n";
    }
    return 0;
}
