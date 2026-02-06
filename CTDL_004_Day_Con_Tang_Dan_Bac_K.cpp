#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[100];
long long ans = 0;

void backtrack(int pos, int cnt, int last)
{
    if (n - pos < k - cnt) return;
    if(cnt == k)
    {
        ans++;
        return;
    }
    
    for(int i = pos; i< n; i++)
    {
        if(a[i] > last)
        {
            backtrack(i +1, cnt + 1, a[i]);
        }
    }
}

int main()
{
    cin >> n >> k;
    for(int i= 0; i< n; i++)
    {
        cin >> a[i];
    }
    backtrack(0,0,LLONG_MIN);
    cout << ans << "\n";
    return 0;
}