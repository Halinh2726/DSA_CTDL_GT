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
        vector<int> a(n), b(n);
        for(int i = 0 ; i< n ; i++) cin >> a[i];
        b = a;
        sort(b.begin(), b.end());
        int check = 1;

        for(int i = 0; i <= n/2 ; i++)
        {
            vector<int> x{a[i], a[n-1-i]};
            vector<int> y{b[i], b[n-i-1]};
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());

            if( x != y)
            {
                check = 0;
                break;  
            }
        }
        if(check) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}