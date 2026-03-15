#include<bits/stdc++.h>
using namespace std;
/*
- Xét từ phải sang trái
+ Nếu là số thì cho vào stack 
+ Nếu gặp kí tự, lấy 2 kí tự từ stack ra ngoài ==> Tính giá trị ==> Đẩy vào stack
*/
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        stack<int> st;

        for(int i = s.size() - 1; i>= 0; i--)
        {
            if(isdigit(s[i]))
            {
                st.push(s[i]- '0');
            }
            else
            {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                if(s[i] == '+') st.push(a+b);
                else if(s[i] == '-') st.push(a-b);
                else if(s[i] == '*') st.push(a*b);
                else if(s[i] == '/') st.push(a/b);
            }
        }
        cout << st.top() << "\n";
    }
    return 0;
}