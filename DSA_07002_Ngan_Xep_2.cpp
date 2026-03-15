#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    stack<int> st;
    while(t--)
    {
        
        string tmp;
        cin >> tmp;
            if(tmp == "PUSH")
            {
                int x;
                cin >> x;
                st.push(x);
            }
            else if(tmp == "POP")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else if(tmp == "PRINT")
            {
                if(st.empty())
                {
                    cout << "NONE\n";
                }
                else
                {
                    cout << st.top() << "\n";
                }
            }
    }
    return 0;
}