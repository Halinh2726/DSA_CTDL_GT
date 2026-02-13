#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> a, int n, int x)
{
    int res = -1;
    int left = 0, right = n-1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(a[mid] >= x)
        {
            res = mid;
            right = mid - 1;
        }
        else if(a[mid] < x)
        {
            left = mid + 1;
        }
    }
    return res;
}

int upperbound(vector<int> a, int n, int x)
{
    int res = -1;
    int left = 0, right = n- 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(a[mid] >= x)
        {
            res = mid;
            left = mid + 1;
        }
        else if(a[mid] < x)
        {
            right = mid - 1;
        }
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i< n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        cout << upper_bound(a.begin(), a.end(), 0)
        - lower_bound(a.begin(), a.end(), 0) << "\n";
    }
}