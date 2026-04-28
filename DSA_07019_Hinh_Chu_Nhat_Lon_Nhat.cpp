#include<bits/stdc++.h>
using namespace std;

/*
Bai toan con : DSA07027
Phần tử bên phải nhỏ hơn
Phần tử cuối cùng bên phải lớn hơn hoặc bằng a[i] 
Cần tìm r[i] cuối cùng bên phải >= và l[i] cuối cùng bên trái >=
Chiều cao a[i]
Chiều rộng r[i] - l[i] + 1
*/

void left(int a[], int n)
{
     stack<int> st;
    int r[n];
    for(int i = n-1; i>= 0; i--)
    {
        while(!st.empty() && a[i] >= st.top())
        {
            st.pop();
        }
        if(st.empty())
        {
            r[i] = -1;
        }
        else
        {
            r[i] = st.top();
        }
        st.push(a[i]);
    }
    
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i< n; i++)
        {
            cin >> a[i];
        }

    }
}