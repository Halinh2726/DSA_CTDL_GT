#include<bits/stdc++.h>
using namespace std;


void bubblesort(int a[], int n)
{
    for(int i = 0; i< n-1; i++)
    {
        for(int j = 1; j< n; j++)
        {
            if(a[i]> a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i =0; i< n;i++)
        {
            cin >> a[i];
        }


    }
}