#include<bits/stdc++.h>
using namespace std;

int n, u;
int a[105][105];
bool visited[105];

// DFS kiểm tra liên thông (bỏ đỉnh cô lập)
void dfs(int u)
{
    visited[u] = true;
    for(int v = 1; v <= n; v++)
    {
        if(a[u][v] && !visited[v])
            dfs(v);
    }
}

bool isConnected()
{
    memset(visited, false, sizeof(visited));

    int start = -1;
    for(int i = 1; i <= n; i++)
    {
        int deg = 0;
        for(int j = 1; j <= n; j++) deg += a[i][j];
        if(deg > 0)
        {
            start = i;
            break;
        }
    }

    if(start == -1) return true; // không có cạnh

    dfs(start);

    for(int i = 1; i <= n; i++)
    {
        int deg = 0;
        for(int j = 1; j <= n; j++) deg += a[i][j];
        if(deg > 0 && !visited[i])
            return false;
    }
    return true;
}

int main()
{
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    int t;
    cin >> t;

    if(t == 1)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cin >> a[i][j];

        if(!isConnected())
        {
            cout << 0;
            return 0;
        }

        int odd = 0;
        for(int i = 1; i <= n; i++)
        {
            int deg = 0;
            for(int j = 1; j <= n; j++)
                deg += a[i][j];
            if(deg % 2 != 0) odd++;
        }

        if(odd == 0) cout << 1;       // Euler
        else if(odd == 2) cout << 2;  // nửa Euler
        else cout << 0;
    }
    else
    {
        cin >> n >> u;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cin >> a[i][j];

        stack<int> st;
        vector<int> path;

        st.push(u);

        while(!st.empty())
        {
            int x = st.top();
            bool found = false;

            for(int v = 1; v <= n; v++)
            {
                if(a[x][v])
                {
                    st.push(v);
                    a[x][v] = a[v][x] = 0; // xóa cạnh
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                path.push_back(x);
                st.pop();
            }
        }

        reverse(path.begin(), path.end());

        for(int x : path)
            cout << x << " ";
    }

    return 0;
}