#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for(int i = 0; i< n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b+n);
        int l = 0, r = n-1;

        while(l >= 0 && a[l] == b[l]) l++;

        if(l == n)
        {
            cout << "0 0\n";
            continue;
        }
        while(r>= 0 && a[r] == b[r]) r--;

        cout << l + 1 << " "<< r+1 <<"\n";
    }
    return 0;
}