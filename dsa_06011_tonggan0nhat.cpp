#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >>n;
        int a[n];
        for(int i= 0; i< n; i++)
        {
            cin >> a[i];
        }

        sort(a, a+n);
        int l = 0, r = n-1;
        int bestsum = a[l] + a[r];

        while(l < r)
        {
            int sum = a[l] + a[r];

            if (abs(sum) < abs(bestsum) || (abs(sum) == abs(bestsum) && sum > bestsum))
            {
                bestsum = sum;
            }

            if(sum < 0)
            {
                l++;
            }

            else if(sum > 0)
                r--;
            else
                break;
        }
        cout << bestsum << "\n";
    }
    return 0;
}