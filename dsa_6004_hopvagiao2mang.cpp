#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int,int> b)
{
    return a.second < b.second;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int a[n], b[m];
        map<int, int> mp;
        for(int i =0; i<n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        for(int i =0; i<m; i++)
        {
            cin >> b[i];
            mp[b[i]]++;
        }

        vector<pair<int,int>> v(mp.begin(), mp.end());

        // sort(v.begin(),v.end(), cmp);
        for(auto it : v)
        {
            cout << it.first << " ";
        }
        cout << "\n";
        for(auto it: v)
        {
            if(it.second == 2)
            {
                cout << it.first << " ";
            }
        }
        cout <<"\n";
    }
}