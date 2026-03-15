#include<bits/stdc++.h>
using namespace std;

stack<int> st;
vector<pair<int, int>> matches;

bool solve(string s)
{
    int n = (int)s.size();
    for(int i = 0; i< n; i++)
    {
        if(s[i] == '(')
        {
            st.push(i);
        }
        else{
            if(st.empty())
                return false;
            matches.push_back({st.top(), i});
            st.top();
        }
    }
    if(!st.empty())
        return false;
    return true;
}

