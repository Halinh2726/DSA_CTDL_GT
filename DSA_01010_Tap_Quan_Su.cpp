#include<bits/stdc++.h>
using namespace std;

int n,k;
int ok = 1;
vector<int> a;
void sinh()
{
    int i = k-1;
    while(i>= 0 && a[i] == n-k+i+1)
    {
        i--;
    }
    if(i< 0)
    {
        for(int i = 0; i< k; i++)
        {
            a[i] = i+1;
        }
    }
    else{
        a[i]++;
        for(int j = i+1; j < k; j++)
        {
            a[j] = a[j-1] + 1;
        }
    }
}

int main()
{
   int t; cin >> t;
   while(t--)
   {
     cin >> n >> k;
     a.resize(k);
     ok = 1;
    vector<int> tmp(k);
    for(int i = 0; i< k ; i++)
    {
        cin >> a[i];
        tmp[i] = a[i];
    }
    for(int i = 0; i< k; i++)
    {
        if(a[i] != n-k+i+1)
        {
            ok = 0;
            break;
        }
    }
    if(ok)
    {
        cout << k <<"\n";
        continue;
    }
    sinh();
    int cnt = 0;
    for(int x =  0; x<k;x++)
    {
        if(find(tmp.begin(), tmp.end(), a[x]) == tmp.end())
        {
            cnt++;
        }
    }
    cout << cnt <<"\n";
   }
    return 0;
}