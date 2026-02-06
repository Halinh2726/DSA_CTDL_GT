#include<bits/stdc++.h>
using namespace std;

// Tim kiem tuan tu
// Tim kiem nhi phan 
/*
sort day a;
left, mid, right;
a[mid] == x break;
a[mid] > x
a[mid] < x
*/

int binary_search(int a[], int n, int x)
{
    int low =0;
    int high = n-1, mid;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(x > a[mid])
            low =mid +1;
        else if(x < a[mid])
            high = mid - 1;
        else
            return(mid);

        mid = (low + high) / 2;
    }
    return (-1);
}

/*
lower_bound : vi tri dau tien
upper_bound : vi tri cuoi cung
*/

int lowerbound(int a[], int n, int x)
{
    int res = -1;
    int left = 0, right = n-1;
    while(left <= right)
    {
        int mid = (left + right)/2;
        if(a[mid] >= x)
        {
            res = mid;
            right = mid-1;
        }
        else if(a[mid] < x)
        {
            left = mid + 1;
        }
    }
    return res;
}

int upperbound(int a[], int n, int x)
{
    int res = -1;
    int left = 0, right = n-1;
    while(left <= right)
    {
        int mid = (left + right) /2;
        if(a[mid] >= x)
        {
            res = mid;
            left = mid + 1;
        }
        else if( x < a[mid])
        {
            right = mid -1;
        }
    }
    return res;
}

int main()
{
    int n,x;
    cin >> n >> x;
    int a[n];
    for(int i = 0; i< n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    binary_search(a,n,x);

}


/*

*/