#include <bits/stdc++.h>
using namespace std;

string solve(int n)
{
    queue<string> q;
    q.push("9");

    while(true)
    {
        string s = q.front(); 
        q.pop();

        long long num = 0;
        for(char c : s)
        {
            num = num * 10 + (c - '0');
            num %= n; // chỉ giữ mod
        }

        if(num == 0) return s;

        q.push(s + "0");
        q.push(s + "9");
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
}