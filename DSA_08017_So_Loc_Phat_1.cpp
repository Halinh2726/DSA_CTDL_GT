#include<bits/stdc++.h>
using namespace std;

void init()
{
    int n;
    cin >> n;

    vector<string> v;
    queue<string> q;

    q.push("6");
    q.push("8");

    while(!q.empty())
    {
        string s = q.front();
        q.pop();

        if(s.length() > n) continue;

        v.push_back(s);

        q.push(s + "6");
        q.push(s + "8");
    }

    for(int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << " ";

    cout << "\n";
}

int main()
{
    int t;
    cin >> t;

    while(t--)
        init();
}