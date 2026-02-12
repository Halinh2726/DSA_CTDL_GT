#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i= 0; i< n; i++) cin >> a[i];
    vector<long long> b, c;
    for(int i = 0; i< n; i++)
    {
        if((i+1) % 2 == 1) b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end(), greater<long long>());

    long long io = 0, ie = 0;

    for(int i= 0; i< n; i++)
    {
        if((i+1)%2 == 1)
        {
            a[i] = b[io++];
        }
        else
        {
            a[i] = c[ie++];
        }
    }
    for(long long x : a)
    {
        cout << x << " ";
    }
    cout <<"\n";
    return 0;
}