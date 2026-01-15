#include<bits/stdc++.h>
using namespace std;

int n;
string s;
int ok = 1;

void KhoiTao()
{
    s.assign(n,'A');
    ok = 1;
}

void Sinh()
{
    int i = n-1;
    while(i>= 0 && s[i] == 'B')
    {
        s[i] = 'A';
        i--;
    }
    if(i< 0) ok = 0;
    else
    {
        s[i] = 'B';
    }
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
            for(int i = 0; i< n; i++)
            {
                cout << s[i];
            }
            cout << " ";
            Sinh();
        }
        cout << "\n";
    }
    return 0;
}