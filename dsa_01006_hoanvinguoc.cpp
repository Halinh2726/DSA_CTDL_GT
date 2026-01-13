#include<bits/stdc++.h>
using namespace std;

int n, ok = 1;
int a[100];

void KhoiTao()
{
    for(int i = 0; i<n; i++)
    {
        a[i] = n-i;
    }
}

void SinhHoanViNguoc()
{
    int i = n-2;
    while(i>= 0 && a[i] < a[i+1])
        i--;
    if(i<0)
    {
        ok = 0;
        return;
    }
    else{
        int j = n-1;
        while(a[j] > a[i])
        {
            j--;
        }
        swap(a[i], a[j]);
        reverse(a+i+1,a+n);
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >>n;
        KhoiTao();
        while(ok)
        {
            for(int i = 0; i< n; i++)
            {
                cout << a[i];
            }
            cout << " ";
            SinhHoanViNguoc();
        }
        cout <<"\n";
        ok = 1;
    }
}