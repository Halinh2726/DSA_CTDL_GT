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
        vector<int> a(n);
        for(int i= 0; i< n; i++)
        {
            cin >> a[i];
        }
        int cur_sum = a[0];
        int max_sum = a[0];

        for(int i = 1; i< n; i++)
        {
            cur_sum = max(a[i], cur_sum + a[i]);
            max_sum = max(max_sum, cur_sum);
        }
        cout << max_sum << "\n";
    }
    return 0;
}