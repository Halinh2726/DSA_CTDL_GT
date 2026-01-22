#include<bits/stdc++.h>
using namespace std;

char x;
int n;
vector<char> a;

void inkq()
{
    for(auto ch: a)
    {
        cout << ch;
    }
    cout <<"\n";
}

void Try(int i, int m)
{
    for(int j = m; j<= x-'A'; j++)
    {
        a[i] = char('A' + j);
        if(i==n-1)
        {
            inkq();
        }
        else Try(i+1,j);
    }
}

int main()
{
    cin >> x >> n;
    a.resize(n);
    Try(0,0);
    return 0;
}