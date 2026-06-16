#include<bits/stdc++.h>
using namespace std;

int n;
int arr[105][105];
vector<int> dsk[105];
vector<int> adj;
bool visited[105];
bool used[105];

void dfs(int i)
{
    visited[i] = true;
    for(int x : dsk[i])
    {
        if(!visited[x])
        {
            dfs(x);
    }
}
}

void cntlt()
{
    
    int cnt = 0;
    memset(visited, false, sizeof(visited));
    for(int i= 1; i<= n; i++)
    {
        if(!visited[i])
        {
            ++cnt;
            dfs(i);
        }
    }
    
    for(int i = 1; i<= n;i++)
    {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        int ans = 0;
        for(int j = 1; j<= n; j++)
        {
            if(!visited[j])
            {
                ++ans;
                dfs(j);
            }
        }
        if(ans > cnt)
            adj.push_back(i);
    }

    cout << adj.size() << "\n";
    for(auto x : adj)
    {
        cout << x << " ";
    }
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j])
            {
                dsk[i].push_back(j);
                dsk[j].push_back(i);
            }
        }
    }

    cntlt();
    return 0;
}