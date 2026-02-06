#include<bits/stdc++.h>
using namespace std;

string a;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> a;
        stack<string> st;
        for(int i = a.size()-1; i >= 0; i--)
        {
            if(isalpha(a[i]))
            {
                st.push(string(1, a[i]));
            }
            else
            {
                string x1 = st.top(); st.pop();
                string x2 = st.top(); st.pop();
                string tmp = '(' + x1 + a[i] + x2 + ')';
                st.push(tmp);
            }
        }
        cout << st.top();
        cout <<"\n";        
    }
    return 0;
}