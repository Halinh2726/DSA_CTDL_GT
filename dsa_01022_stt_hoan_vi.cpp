#include<bits/stdc++.h>
using namespace std;

int n;
int ok = 1;
vector<int> a;

void khoitao()
{
    a.resize(n);
    for(int i = 0; i< n; i++)
    {
        a[i] = i+1;
    }
}

void sinh()
{
    int i = n-2;
    while(i>= 0 && a[i] >= a[i+1]) i--;
    if(i <0)
    {
        ok = 0;
        return;
    }
    else
    {
        int j = n-1;
        while(a[i] > a[j]) j--;
        swap(a[i], a[j]);
        reverse(a.begin() +i+1, a.end());
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> tmp(n);
        a.resize(n);
        for(int i = 0; i< n;i++)
        {
            cin >> tmp[i];
        }
        khoitao();
        ok = 1;
        int cnt = 1;
        while(ok)
        {
            int check = 1;
            for(int i = 1; i<= n; i++)
            {
                if(a[i] != tmp[i])
                {
                    check = 0;
                    break;
                }
            }
            if(check)
            {
                cout << cnt <<"\n";
                break;
            }
            sinh();
            cnt++;
        }
    }
    return 0;
}