#include<bits/stdc++.h>
using namespace std;

const int MAXA = 100000;
int cnt[MAXA + 1];

bool cmp(int x, int y)
{
    if(cnt[x] != cnt[y])
    {
        return cnt[x] > cnt[y];
    }
    return x < y;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i< n;i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }

        sort(a.begin(), a.end(), cmp);

        for(int x:a)
        {
            cout << x <<" ";
        }
        cout <<"\n";
    }
    return 0;
}