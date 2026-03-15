#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        stack<char> st;

        for(auto ch: s)
        {
            if(ch == '(')
                st.push(ch);
            else
            {
                if(!st.empty() && st.top() == '(')
                {
                    st.pop();
                }
                else st.push(ch);
            }
        }

        int open = 0, close= 0;

        while(!st.empty())
        {
            if(st.top() == '(')
                open++;
            else close++;
            st.pop();
        }

        int tmp = (open + 1)/ 2 + (close+  1) / 2;
        cout << tmp << "\n";
    }
    return 0;
}