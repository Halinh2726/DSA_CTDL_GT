#include<bits/stdc++.h>
using namespace std;
/*
Duyệt phần tử từ phải sang trái
- Nếu gặp toán hạng (A,B,C,D) thì đẩy vào trong stack
- Khi gặp đến toán tử (+-*...) thì 
    + lấy từ stack ra 2 phần tử
    + sau đó ghép toán hạng đã lấy ra với toán tử thành một nhóm
    + rồi push vào stack 
*/

bool check(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        stack<string> st;
        for(int i = s.size() - 1; i>= 0; i--)
        {
            if(!check(s[i]))
            {
                st.push(string(1,s[i]));
            }
            else
            {
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();

                string tmp = a + b + s[i];
                st.push(tmp);
            }
        }
        cout << st.top() << "\n";
    }
    return 0;
}