#include<bits/stdc++.h>
using namespace std;

/*
size_s: do dai xau
maxn : so lan xuat hien nhieu nhat cua 1 ki tu trong s
Khi: (maxn - 1)*(n - 1) <= size_s - maxn thi tm yc de bai
*/
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        long long size_s = s.length();
        map<char, int> mp;
        
        for(char c : s)
            mp[c]++;
        
        int maxn = 0;
        for(auto x: mp)
        {
            maxn = max(maxn, x.second);
        }

        long long tmp = (maxn - 1) * (n-1);
        if(tmp > (size_s - maxn))
            cout << "-1\n";
        else    cout << "1\n";
    }
    return 0;
}