#include<bits/stdc++.h>
using namespace std;

int first_pos(int a[], int n, int x)
{
    int l= 0, r = n-1, res = -1;
    while(l<= r)
    {
        int mid = (l+r) / 2;
        if(a[mid] == x)
        {
            res = mid;
            r = mid -1;
        }
        else if(a[mid] < x){
            l = mid +1;
        }
        else{
            r = mid -1;
        }
    }
    return res;
}

int last_pos(int a[], int n, int x)
{
    int l =0, r = n-1, res = -1;
    while(l <= r)
    {
        int mid = (l+r) / 2;
        if(a[mid] == x)
        {
            res = mid;
            l= mid +1;
        }
        else if(a[mid] < x)
        {
            l = mid + 1;
        }
        else{
            r = mid -1;
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
        int k;
        cin >> k;
        int a[n];
        for(int i= 0; i< n; i++)
        {
            cin >> a[i];
        }
        int check = 0;
        for(auto x: a)
        {
            if(x == k)
            {
                cout << last_pos(a,n,k)-first_pos(a,n,k) + 1 << "\n";
                check = 1;
                break;
            }
            else{
                check = 0;
            }
        }
        if(!check)
            cout << "-1\n";
    }
    return 0;
}