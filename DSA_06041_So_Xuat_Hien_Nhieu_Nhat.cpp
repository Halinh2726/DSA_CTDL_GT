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
        for(int i = 0; i< n; i++)   cin >> a[i];

        long long tmp = n/2;
        map<long long,long long> mp;
        int check = 0;
        for(int i = 0; i<n; i++)    mp[a[i]]++;
        for(auto x : mp){
            if(x.second > tmp)
            {
                cout << x.first << "\n";
                check = 1;
                break;
            }
        }
        if(!check) cout << "NO\n";
    }
    return 0;
}