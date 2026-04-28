#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
queue<string> q;

int main()
{
    int n;
    cin >> n;
    q.push("");
    while(!q.empty())
    {
        string u = q.front();
        q.pop();
        if(u.size() > n) break;
        if(u.size() == n) ans.push_back(u);
        q.push(u + '0');
        q.push(u + '1');
    }
    for(auto x : ans)
    {
        cout << x << "\n";
    }
    return 0;
}


