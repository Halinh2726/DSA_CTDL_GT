#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> st;
    string s;
    cin >> s;
    int check = 1;
    for(int i = 0; s[i]; i++)
    {
        if(s[i] == '(' || s[i] == '[')
        {
            st.push(s[i]);
        }

        else{
            if(!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                check = 0;
                break;
            }
        }
    }
    if(check)
    {
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}