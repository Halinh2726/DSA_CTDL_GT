#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i< n; i++) cin >> a[i];
        vector<long long> b(n-1);
        for(int i = 0; i< n-1; i++) cin >> b[i];

        int i = 0, j = 0;
        while(i <= j)
        {
            if(a[i] != b[j])
            {
                cout << i + 1 << "\n";
                break;
            }
            i++;
            j++;
        }
    }
    return 0;
}
