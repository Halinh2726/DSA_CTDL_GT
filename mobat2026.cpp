#include<bits/stdc++.h>
using namespace std;

int n, ok = 1;
vector<int> a;

void khoitao()
{
    for(int i = 0; i< n; i++)
    {
        a[i] = 6;
    }
}

void sinh_phat_loc()
{
    int i = n-1;
    while(i>= 0 && a[i] == 8)
    {
        a[i] = 6;
        i--;
    }

    if(i< 0) ok = 0;
    else{
        a[i] = 8;
    }
}

bool check()
{
    if(a[0] != 8 || a[n-1] != 6) return false;
    for(int i = 0; i< n-1; i++)
    {
        if(a[i] == 8 && a[i+1] == 8) return false;
    }

    for(int i =0; i< n-3; i++)
    {
        if(a[i] == 6 && a[i+1] == 6 && a[i+2] == 6 && a[i+3]==6) return false;
    }
    return true;
}

int main()
{
    cin >> n;
    a.resize(n);
    khoitao();
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
        sinh_phat_loc();
    }
    return 0;
}