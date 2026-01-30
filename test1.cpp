#include <bits/stdc++.h>
using namespace std;

void count_sort(int a[], int n)
{
    int cnt[1000001] = {0};
    int mx = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
        mx = max(mx, a[i]);
    }

    for(int i = 0; i <= mx; i++)
    {
        while(cnt[i]--)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[1000001];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    count_sort(a, n);
    return 0;
}
