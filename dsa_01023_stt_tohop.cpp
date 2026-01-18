#include<bits/stdc++.h>
using namespace std;

int n,k;
int ok = 1;
vector<int> a;

void khoitao()
{
    a.resize(k);
    for(int i = 0; i< k; i++)
    {
        a[i] = i+1;
    }
}

void sinh_to_hop()
{
    int i = k-1;
    while(i>= 0 && a[i] == n-k+i+1) i--;
    if(i < 0)
    {
        ok = 0;
        return;
    }
    else
    {
        a[i]++;
        for(int j = i+1; j< k; j++)
        {
            a[j] = a[j-1]+1;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        vector<int> tmp(k);
        for(int i = 0; i< k; i++)
        {
            cin >> tmp[i];
        }

        khoitao();
        ok = 1;
        int cnt = 1;

        while(ok)
        {
            int check = 1;
            for(int i = 0; i< k; i++)
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
            if (!ok) break;   
            sinh_to_hop();
            cnt++;
        }
    }
    return 0;
}