#include<bits/stdc++.h>
using namespace std;

int cnt[10000001] = {0};
void count_sort(int a[],int n)
{
    if(n==0) return;
    int maxn = a[0];
    for(int i = 0; i<n; i++)
    {
        cnt[a[i]]++;
        maxn = max(maxn, a[i]);
    }

    for(int i = 0; i <= maxn; i++)
    {
        while(cnt[i]> 0)
        {
            cout << i << " ";
            cnt[i]--;
        }
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[10000001];
    for(int i = 0; i< n; i++)
    {
        cin >> a[i];
    }
    count_sort(a,n);

    }
        return 0;
}