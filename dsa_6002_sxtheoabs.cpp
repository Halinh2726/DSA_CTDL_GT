#include<bits/stdc++.h>
using namespace std;

int k;

bool cmp(int x, int y)
{
    return abs(x - k) < abs(y - k);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n >> k;
        int a[n];
        for(int i =0;i< n; i++)
        {
            cin >> a[i];
        }
        stable_sort(a,a+n, cmp);

        for(int i = 0;i < n; i++)
        {
            cout << a[i] << " ";
        }
        // int tmp[n];
        // for(int i =0; i< n; i++)
        // {
        //     tmp[i] = abs(k-a[i]);
        // }
        // sort(tmp, tmp+n);

        // for(int i=0;i< n; i++)
        // {
        //     cout << abs(k - tmp[i]) <<" ";
        // }
        cout <<"\n";
    }
    return 0;
}