#include<bits/stdc++.h>
using namespace std;

int n, ok = 1;
char a[100];

void KhoiTao()
{
    for(int i= 0; i< n; i++)
    {
        a[i]= 'A';
    }
}
void Sinh()
{
    int i = n-1;
    while(i>= 0 && a[i] == 'H')
    {
        a[i] = 'A';
        i--;
    }
    if(i< 0) ok = 0;
    else{
        a[i] = 'H';
    }
}

bool check()
{
    if(a[0] != 'H' || a[n-1] != 'A') return false;
    for(int i = 0;i< n; i++)
    {
        if(a[i] =='H' && a[i+1] == 'H') return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        KhoiTao();
        ok = 1;
        while(ok)
        {
            if(check())
            {
                for(int i = 0; i< n; i++)
                {
                    cout << a[i];
                }
                cout << "\n";
            }
            Sinh();
        }
        cout << "\n";
    }
}
