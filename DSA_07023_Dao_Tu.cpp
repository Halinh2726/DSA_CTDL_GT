#include<bits/stdc++.h>
using namespace std;

/*
- Tách từ trong string
- Dùng stringstream để tách từ sau đó đẩy vào stack
*/
int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while(t--)
    {
        string s;
        getline(cin,s);
        stack<string> st;

        stringstream ss(s);
        string word;
        while(ss >> word)
        {
            st.push(word);
        }

        while(!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << "\n";
    }
    return 0;
}