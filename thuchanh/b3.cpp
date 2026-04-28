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
        stack<int> st;
        vector<int> res(s.size(), -1);

        for(int i = 0; i< s.size(); i++)
        {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')')
                if(!st.empty())
                {
                    int j = st.top();
                    st.pop();
                    res[j] = 0;
                    res[i] = 1;
                }
        }

        for(int i = 0; i< s.size(); i++)
        {
            if(s[i] == '(' || s[i] == ')')
            {
                cout << res[i];
            }
            else
                cout << s[i];
        }
        cout << st.top() << "\n";
    }
    return 0;
}