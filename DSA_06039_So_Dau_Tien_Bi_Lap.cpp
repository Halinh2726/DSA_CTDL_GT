#include<bits/stdc++.h>
using namespace std;
/*

*/
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector<pair<long long, int>> a(n);
        for(int i = 0; i< n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        
        sort(a.begin(), a.end());

        int min_index = n;
        long long tmp = -1;

        for(int i = 1; i< n; i++)
        {
            if(a[i].first == a[i-1].first)
            {
                int xh_lan_dau = min(a[i].second, a[i-1].second);

                if(xh_lan_dau < min_index)
                {
                    min_index = xh_lan_dau;
                    tmp = a[i].first;
                }
            }
        }
        if(tmp == -1) cout <<"NO\n";
        else cout << tmp <<"\n";
    }
    return 0;
}