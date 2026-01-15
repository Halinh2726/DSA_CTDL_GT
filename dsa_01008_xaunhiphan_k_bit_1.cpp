#include<bits/stdc++.h>
using namespace std;

int n,k, ok = 1;
long long a[100];

void khoitao()
{
    for(long long i =0; i< n; i++)
    {
        a[i] = 0;
    }
}

void Sinh()
{
    int i = n-1;
    while(i>= 0 && a[i] == 1)
    {
        a[i] = 0;
        i--;
    }
    if(i< 0) ok = 0;
    else
    {
        a[i] = 1;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        khoitao();
        ok = 1;
        long long cnt = 0;
        while(ok)
        {
            
            for(long long i = 0; i< n; i++)
            {
                if(a[i] == 1) cnt++;
            }
            if(cnt == k)
            {
                for(long long i = 0; i< n; i++)
                {
                    cout << a[i];
                }
                cout << "\n";
            }
            Sinh();
            cnt = 0;
        }
    cout <<"\n";
    }
}