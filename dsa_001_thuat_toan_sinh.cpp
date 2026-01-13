#include<bits/stdc++.h>
using namespace std;

int n, ok;
vector<int> a(100);

void Khoi_Tao()
{
    for(int i = 0; i< n; i++)
    {
        a[i] = 0;
    }
}

void Sinh_ke_tiep()
{
    int i = n-1;
    while(i >= 0 && a[i] == 1)
    {
        a[i] = 0;
        i--;
    }
    if(i <  0) ok = 1;
    else a[i] = 1;
}

int kiem_tra()
{
    int l = 0, r = n-1;
    while(l <= r)
    {
        if(a[l] != a[r]) return 0;
        l++;
        r--;
    }
    return 1;
}

int main()
{
    cin >> n;
    Khoi_Tao();
    while(!ok)
    {
        if(kiem_tra())
        {
            for(int i = 0; i< n; i++)
            {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
        Sinh_ke_tiep();
    }
    return 0;
}