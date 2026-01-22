#include<bits/stdc++.h>
using namespace std;

int a[105];
int cnt = 0;
int ok = 0;

void bubblesort(int a[], int n)
{
    for(int i = 0; i< n-1; i++)
    {
        for(int j = 0; j< n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                ok = 1;
            }
        }
        if(ok)
        {
            cout << "Buoc " << i+1 << ": ";
            for(int k =0; k<n; k++)
            {
                cout << a[k] << " ";
            }
            cout << "\n";
        }
        ok = 0;
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i< n; i++)
    {
        cin >> a[i];
    }

    bubblesort(a,n);
    return 0;
}