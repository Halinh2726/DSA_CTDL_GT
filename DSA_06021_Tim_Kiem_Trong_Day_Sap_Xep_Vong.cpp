#include<bits/stdc++.h>
using namespace std;

long long search(long long a[], int n, int k)
{
    long long left = 0, right = n-1;
        while(left <= right)
        {
            long long mid = left + (right - left) / 2;
            if(a[mid] == k)
                return mid + 1; 
            if(a[left] <= a[mid])
            {
                if(a[left] <= k && k <= a[mid])
                {
                    right = mid -1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if(a[mid] <= k && k <= a[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid -1;
                }
            }
        }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        long long a[n];
        for(int i =0;i< n; i++)
            cin >> a[i];
        cout << search(a,n,k) << "\n";      
    }
    return 0;
}