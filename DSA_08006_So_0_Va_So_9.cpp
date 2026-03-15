#include<bits/stdc++.h>
using namespace std;

void init()
{
    int n;
    cin >>n;
    queue<string> q;
    q.push("9");

    while(!q.empty())
    {
        string s = q.front();
        q.pop();
        long long tmp = stoll(s);
        if(tmp % n == 0)
        {
            cout << s << "\n";
            return;
        }
        q.push(s + '0');
        q.push(s + '9');
    }
    cout << "\n";
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        init();
    }
    return 0;
}