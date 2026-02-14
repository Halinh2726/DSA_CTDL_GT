#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >>n >> k;
        k = min(k, n-k);
        vector<int> a(n);
        for(int i = 0; i< n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        vector<int> mang1;
        vector<int> mang2;
        for(int i = 0; i< k; i++)
        {
            mang1.push_back(a[i]);
        }
        for(int i = k; i< n; i++)
            mang2.push_back(a[i]);
        
        // for(auto x : mang1)
        //     cout << x << " ";
        // cout << "\n";
        // for(auto x: mang2)
        //     cout << x << " ";
        // cout <<"\n";
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i< k; i++)
            sum1 += mang1[i];
        for(int i = 0; i< mang2.size(); i++)
        {
            sum2 += mang2[i];
        }

        int hieu = 0;
        hieu = abs(sum2 - sum1);
        cout << hieu <<"\n";
    }
    return 0;
}