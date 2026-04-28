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
        q.push(u+'1');
    }
    for(auto x : ans)
    {
        cout << x << " ";
    }
    cout <<"\n";
    return 0;
}

/*
stack<string> st;
st.push("");
while(!st.empty())
{
    string tp = st.top();
    st.pop();

    if(tp.size() == n)
    {
        cout << tp <<"\n";
        continue;
    }
    st.push(tp + "1");
    st.push(tp + "0");
}
*/