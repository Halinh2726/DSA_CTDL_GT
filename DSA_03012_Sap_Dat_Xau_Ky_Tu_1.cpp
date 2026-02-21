#include<bits/stdc++.h>
using namespace std;

/*
n la do dai string s;
maxn : so lan xuat hien nhieu nhat cua 1 ki tu trong string s;
dkien de co the sx xen ke la : maxn <= (n+1)/2;
*/

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        map<char, int> mp;

        for(auto x: s)
        {
            mp[x]++;
        }

        int maxn = 0;
        for(auto x : mp)
        {
            maxn = max(maxn, x.second);
        }

        if(maxn > (n+1)/2)
        {
            cout << "-1\n";
        }
        else cout << "1\n";
    }
    return 0;
}