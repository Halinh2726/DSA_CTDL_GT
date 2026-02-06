#include<bits/stdc++.h>
using namespace std;

struct cv
{
    int oldid;
    int s;
    int f;
};

bool cmp(cv x, cv y)
{
    if(x.f == y.f)
        return x.s < y.s;
    return x.f < y.f;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cv a[n];
        for(int i= 0; i< n; i++)
        {
            a[i].oldid = i;
            cin >> a[i].s;
        }
        for(int i = 0; i< n; i++)
            cin >> a[i].f;
        sort(a, a+n, cmp);
        int lf = 0;
        int cnt = 0;
        for(int i= 0; i< n; i++)
        {
            if(a[i].s >= lf)
            {
                // cout << a[i].oldid << " ";
                // cout <<"\n";
                cnt++;
                lf = a[i].f;
            }
        }
        cout << cnt <<"\n";
    }
    return 0;
}