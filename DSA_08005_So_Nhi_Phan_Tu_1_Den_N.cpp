#include<bits/stdc++.h>
using namespace std;

void init()
{
    int n;
    cin >> n;
    queue<string> q;
    q.push("1");

    for(int i = 1; i<=n; i++)
    {
        string s;
        s = q.front();
        q.pop();

        cout << s << " ";

        q.push(s + '0');
        q.push(s + '1');
    }
    cout <<"\n";
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