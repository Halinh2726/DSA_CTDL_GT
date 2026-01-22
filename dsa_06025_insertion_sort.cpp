#include<bits/stdc++.h>
using namespace std;

int n;
int a[105];
int ok;
int cnt;

void insertion_sort(int a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int x = a[i];
        int pos = i-1;
        while(pos >= 0 && x < a[pos])
        {
            a[pos+1] = a[pos];
            pos--;
            ok = 1;
        }
        a[pos+1] = x;
        
        cout << "Buoc " << i << ": ";
        for(int j = 0; j<= i; j++)
        {
            cout << a[j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i< n; i++)
    {
        cin >> a[i];
    }
    cout << "Buoc 0: " << a[0] << "\n";
    insertion_sort(a,n);
    return 0;
}