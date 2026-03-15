#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    string tmp;

    while(cin >> tmp)
    {
        if(tmp == "push")
        {
            int x;
            cin >> x;
            st.push(x);
        }
        else if(tmp == "pop")
        {
            if(!st.empty())
            {
                st.pop();
            }
        }
        else if(tmp == "show")
        {
            if(st.empty())
            {
                cout << "empty\n";
            }
            else{
                stack<int> temp = st;
                vector<int> v;

                while(!temp.empty())
                {
                    v.push_back(temp.top());
                    temp.pop();
                }

                for(int i = v.size() - 1; i>= 0; i--)
                {
                    cout << v[i];
                    if(i != 0) cout << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}