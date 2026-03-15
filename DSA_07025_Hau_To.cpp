// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n;
//         cin >> n;
//         stack<long long> st;

//         for(int i= 0; i< n; i++)
//         {
//             string s;
//             cin >> s;
//             if(s == "+" || s == "-" || s == "*" || s == "/")
//             {
//                 long long b = st.top(); st.pop();
//                 long long a = st.top(); st.pop();
                
//                 if(s == "+") st.push(a+b);
//                 else if(s == "-") st.push(a-b);
//                 else if(s == "*") st.push(a*b);
//                 else if(s == "/") st.push(a/b);
                
//             }
//             else
//             {
//                  st.push(stoll(s));
//             }
//         }
//         cout << st.top() << "\n";
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        stack<long long> st;

        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            if(s == "+" || s == "-" || s == "*" || s == "/" || s == "–")
            {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();

                if(s == "+") st.push(a + b);
                else if(s == "-" || s == "–") st.push(a - b);
                else if(s == "*") st.push(a * b);
                else st.push(a / b);
            }
            else
            {
                st.push(stoll(s));
            }
        }

        cout << st.top() << endl;
    }
}