#include<bits/stdc++.h>
using namespace std;

int search(int a[], int n, int x)
{
    int cnt = 0;
    for(int i=0;i < n; i++)
    {
        if(a[i] == x){
            cnt++;

        }
    }
    if(cnt == 0) return -1;
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        int a[n];
        for(int i = 0;i< n; i++)
        {
            cin >> a[i];
        }

        cout << search(a,n,k) << "\n";
    }
    return 0;
}