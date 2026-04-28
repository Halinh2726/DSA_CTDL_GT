// #include<bits/stdc++.h>
// using namespace std;

// int n, m;
// bool visited[1001];
// int cnt = 0;
// set<int> adj[1001];
// int degree[1001];
// void reset()
// {
//     for(int i= 0; i<n;i++)
//     {
//         degree[i] = 0;
//     }
// }

// void ip()
// {
//     cin >> n >>m;
//     reset();
//     for(int i = 0; i<m;i++)
//     {
//         int x,y;
//         cin >> x >> y;
//         adj[x].insert(y);
//         adj[y].insert(x);
//         degree[x]++;
//         degree[y]++;
//     }
// }
/*
void euler(int v)
{
    stack<int> st;
    vector<int> EC;
    st.push(v);
    while(!st.empty())
    {
        int x = st.top();
        if(adj[x].size() != 0)
        {
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        }
        else
        {
            st.pop();
            EC.push_back(x);
        }
    }
    reverse(begin(EC), end(EC));
}
*/
/*
Chu trình Euler (in ra 2)
 Tất cả các đỉnh có bậc chẵn

Đường đi Euler (in ra 1)
 Có đúng 2 đỉnh bậc lẻ

Không có (in ra 0)
Các trường hợp còn lại
*/
// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         ip();
        
//         int odd = 0;
//         for(int i = 1; i<= n; i++)
//         {
//             if(degree[i] % 2 != 0) odd++;
//         }
//         if(odd == 0) cout << 2 << "\n";
//         else if(odd == 2) cout << 1 <<"\n";
//         else cout << 0 << "\n";
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int degree[1001];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        for(int i = 1; i <= n; i++) degree[i] = 0;

        for(int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            degree[x]++;
            degree[y]++;
        }

        int odd = 0;
        for(int i = 1; i <= n; i++)
        {
            if(degree[i] % 2 != 0) odd++;
        }

        if(odd == 0) cout << 2 << "\n";
        else if(odd == 2) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}