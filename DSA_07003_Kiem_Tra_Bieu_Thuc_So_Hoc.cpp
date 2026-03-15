#include<bits/stdc++.h>
using namespace std;

bool check(string s)
{
    stack<char> st;

    for(char ch:s)
    {
        if(ch == ')')
        {
            bool tmp = false;

            while(!st.empty() && st.top() != '(')
            {
                char top = st.top();
                if(top == '+' || top =='-' || top == '/' || top == '*')
                {
                    tmp= true;
                }
                st.pop();
            }

            if(!st.empty())
            {
                st.pop();
            }

            if(!tmp)
            {
                return true;
            }
        }
        else
        {
            if(ch !=' ') st.push(ch);
        }
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string exp;
        getline(cin, exp);

        if(check(exp))
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}