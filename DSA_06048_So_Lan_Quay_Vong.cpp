#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        vector<long long> b(n);
        for(int i = 0; i< n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        // sort(a.begin(), a.end());
        // for(int i = 0; i< n; i++) cout << a[i] << " ";
        // cout << "\n";

        long long k = 0;
        for(int i = 1; i< n; i++)
        {
            if(a[i] < a[i-1])
            {
                k = i;
                break;
            }
            // if(a[i] == b[1])
            // {
            //     cout << i << "\n";
            //     break;
            // }
        }
        cout << k <<"\n";
    }
    return 0;
}