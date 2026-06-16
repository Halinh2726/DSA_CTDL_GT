#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> adj[10005];
bool visited[10005];
vector<pair<int, int>> caykhung;
void chuyendscanhsangdske()
{
    for(int i = 1; i<= m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void reset()
{
    for(int i = 1; i<= n; i++)
    {
        adj[i].clear();
    }
    memset(visited, false, sizeof(visited));
    caykhung.clear();
}

void bfs(int i)
{
    queue<int> q;
    q.push(i);
    visited[i] = true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto x : adj[u])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x] = true;

                caykhung.push_back({u, x});
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >>m >>k;
        reset();
        chuyendscanhsangdske();

        bfs(k);
        int cnt = 0;
        
        for(int i = 1; i<= n; i++)
        {
            if(visited[i])
                ++cnt;
        }
        if(cnt != n)
            cout << "-1\n";
        else
        {
            for(auto x : caykhung)
            {
                cout << x.first << " " << x.second << "\n";
            }
        }
    }
    return 0;
}