#include<bits/stdc++.h>
using namespace std;

string a,b;
int k;

string solve(int i, int carry)
{
    if(i < 0)
    {
        if(carry)
        {
            return string(1, carry + '0');
        }
        return "";
    }
    int x = a[i] - '0';
    int y = b[i] - '0';

    int sum = x+y+carry;
    return solve(i-1, sum/k) + char(sum%k + '0');
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> k >> a >> b;
        while(a.size() < b.size())  a = '0' + a;
        while(b.size() < a.size()) b = '0' + b;
        cout << solve(a.size() - 1 , 0) << "\n";
    }
}