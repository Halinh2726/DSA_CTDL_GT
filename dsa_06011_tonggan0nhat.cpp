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

        long long minx = LLONG_MAX;
        for(int i = 0; i< n-1; i++)
        {
            for(int j = i +1 ; j< n; j++)
            {
                if(llabs(a[i] + a[j]) < llabs(a[minx]))
                    minx = a[i] + a[j];
            }
        }
        cout << minx <<"\n";
    }
    return 0;
}
