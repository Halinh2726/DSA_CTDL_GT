#include<bits/stdc++.h>
using namespace std;

int n;
int a[105][105];
bool visited[105];

void dfs(int u)
{
    visited[u] = true;
    for(int v = 1; v <= n; v++)
    {
        if(a[u][v] == 1 && !visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];

    // DFS lần 1
    memset(visited, false, sizeof(visited));
    dfs(1);

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            cout << "not strongly connected";
            return 0;
        }
    }

    // Tạo đồ thị đảo
    int b[105][105];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            b[i][j] = a[j][i];

    // copy lại
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            a[i][j] = b[i][j];

    // DFS lần 2
    memset(visited, false, sizeof(visited));
    dfs(1);

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            cout << "not strongly connected";
            return 0;
        }
    }

    cout << "strongly connected";

    return 0;
}