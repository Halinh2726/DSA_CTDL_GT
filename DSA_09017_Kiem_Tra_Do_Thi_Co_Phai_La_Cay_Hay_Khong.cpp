#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1005];
bool visited[1005];
int cnt;
void chuyendscanhsangdske()
{
    for(int i= 1; i<= m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int i)
{
    visited[i] = true;
    cnt++;
    for(auto x: adj[i])
    {
        if(!visited[x])
        {
            dfs(x);

        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        m = n - 1;
        for(int i= 1; i<= n;i++)
            adj[i].clear();
        memset(visited, false, sizeof(visited));
        chuyendscanhsangdske();
        cnt = 0;
        dfs(1);
        if(cnt == n) cout << "YES\n";
        else{
            cout << "NO\n";
        }
    }
    return 0;
}