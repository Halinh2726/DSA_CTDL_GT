#include<bits/stdc++.h>
using namespace std;

string res;

void solve(string s, int k, int pos)
{
    if(k == 0) return;

    int sz = s.size();

    // tim max tu dau den cuoi
    char maxn = s[pos];
    for(int i = pos +1; i< sz; i++)
    {
        if(s[i] > maxn) maxn = s[i];
    }

    if(maxn != s[pos]) k--;

    for(int i = sz - 1; i>= pos; i--)
    {
        if(s[i] == maxn)
        {
            swap(s[pos], s[i]);

            if(s > res) res = s;

            solve(s,k,pos+1);

            swap(s[pos], s[i]);
        }
    }
}

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
        
        res = s;
    solve(s,n,0);
    cout << res <<"\n";
    }
    return 0;
}