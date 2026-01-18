#include<bits/stdc++.h>
using namespace std;

int n, k;
int ok = 1;
string s;

void khoitao()
{
    s.resize(k);
    for(int i= 0; i< k; i++)
    {
        s[i] = ('A'+i);
    }
}

void sinh_to_hop()
{
    int i = k-1;
    while(i>= 0 && s[i] == ('A' + (n-k+i)))
    {
        i--;
    }
    if(i<0)
    {
        ok =0;
        return;
    }
    else{
        s[i]++;
        for(int j = i+1; j< k; j++)
        {
            s[j] = (s[j-1] + 1);
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
        khoitao();
        ok = 1;
        while(ok)
        {
            for(int i = 0; i< k;i++)
            {
                cout << s[i];
            }
            cout << "\n";
            sinh_to_hop();
        }
        
    }
    return 0;
}