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
        int a[n];
        for(int i = 0;i < n; i++)
        {
            cin >> a[i];
        }

        set<int> se;
        int tmp;
        for(int i=0; i< n; i++)
        {
            while(a[i])
            {
                tmp = a[i] % 10;
                se.insert(tmp);
                a[i] /= 10;
            }
        }
        for(auto x: se)
        {
            cout << x << " ";
        }
        cout <<"\n";
    }
    return 0;
}