#include<bits/stdc++.h>
using namespace std;

int swapn(int a[], int n)
{
    if(n <= 1) return 0;
    vector<pair<int,int>> b(n);
    for(int i = 0;i<n;i++)
    {
        b[i] = {a[i], i};
    }
    sort(b.begin(), b.end());

    vector<bool> visited(n,false);
    int ans = 0;
    
    for(int i = 0;i < n; i++)
    {
        if(visited[i] || b[i].second == i)
        {
            continue;
        }
        int cycle_len = 0;
    int j =i;

    while(!visited[j])
    {
        visited[j] = true;
        j = b[j].second;
        cycle_len++;
    }

    if(cycle_len > 1)
    {
        ans += cycle_len -1;
    }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i= 0;i< n; i++)
        {
            cin >> a[i];
        }

        cout << swapn(a,n) << "\n";
    }
    return 0;
}