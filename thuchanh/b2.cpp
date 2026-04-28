#include<bits/stdc++.h>
using namespace std;

bool cmp(string st)
{
    return st == "+" || st == "-" || st == "*" || st =="/";
}
long long calc(long long a, long long b, string st)
{
    if(st == "+") return a+b;
    if(st == "-") return a-b;
    if(st == "*") return a*b;
    if(st == "/") return a/b;
    return 0;
}

long long check(vector<string> s)
{
    stack<long long > st;
    for(int i = 0; i< s.size(); i++)
    {
        if(!cmp(s[i]))
        {
            st.push(stoll(s[i]));
        }
        else 
        {
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            st.push(calc(a,b,s[i]));
        }
    }
    return st.top();
}

long long check2(vector<string> s)
{
    stack<long long> st;
    for(int i = s.size() - 1; i>= 0; i--)
    {
        if(!cmp(s[i]))
        {
            st.push(stoll(s[i]));
        }
        else 
        {
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            st.push(calc(a,b,s[i]));
        }
    }
    return st.top();
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; 
        cin >> n;
        vector<string> v(n);
        for(int i = 0; i< n; i++)
            cin >> v[i];
        if(cmp(v[0]))
            cout << check(v) << "\n";
        else    
            cout << check2(v) << "\n";
    }
}