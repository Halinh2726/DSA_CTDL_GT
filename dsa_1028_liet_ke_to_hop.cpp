#include<bits/stdc++.h>
using namespace std;

int n, k;
int ok = 0;
vector<int> a;

int main()
{
    cin >> n >> k;
    a.resize(n);
    set<int> s;
    for(int i = 0; i< n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    vector<int> tmp(s.begin(), s.end());
    int m = tmp.size();

    vector<int> cnt(k);
    for(int i = 0; i< k; i++)
    {
        cnt[i] = i;
    }
    ok = 1;
    while(ok)
    {
        for(int i = 0; i< k; i++)
        {
            cout << tmp[cnt[i]] << " ";
        }
        cout << "\n";
        int i = k-1;
        while(i>= 0 && cnt[i] == m-k+i)
        {
            i--;
        }
        if(i<0)
        {
            ok = 0;
            break;
        }
        else{
            cnt[i]++;
            for(int j = i+1; j< k; j++)
            {
                cnt[j] = cnt[j-1]+1;
            }
        }
    }
    return 0;
}