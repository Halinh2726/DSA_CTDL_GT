#include<bits/stdc++.h>
using namespace std;

// Selection sort
void selection_sort(int a[], int n)
{
    for(int i = 0; i< n-1; i++)
    {
        int minidx = i;
        for(int j = i+1; j< n; j++)
        {
            if(a[minidx] > a[j])
                minidx = j;
        }
        swap(a[i], a[minidx]);
    }
}

// Insertion sort
void insertion_sort(int a[], int n)
{
    for(int i = 1; i< n; i++)
    {
        int key = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }
}

// Bubble sort
void bubble_sort(int a[], int n)
{
    for(int i = 0; i< n; i++)
    {
        bool check = false;
        for(int j = 0; j< n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                check = true;
                swap(a[j], a[j+1]);
            }
        }
        if(!check) break;
    }
}

// Radix sort
void count_sort(int a[], int n, int pos)
{
    int count[10] = {0}, presum[10] = {0};

    for(int i = 0; i< n; i++)
    {
        count[(a[i] / pos) % 10]++;
    }

    presum[0] = count[0];
    for(int i = 1; i< 10; i++)
    {
        presum[i] = presum[i-1] + count[i];
    }

    int ans[n];
    for(int i = n-1; i >= 0; i--)
    {
        ans[presum[(a[i]/pos) % 10] -1] = a[i];
        presum[(a[i]/pos) %10]--;
    }

    for(int i = 0; i< n; i++)
    {
        a[i]= ans[i];
    }
}


int main()
{
    int n; cin >> n;
    int a[n];
    for(int i = 0;i< n; i++) cin >> a[i];
    bubble_sort(a,n);
    for(auto x: a) cout << x << " ";
    return 0;
}


// Merge sort

