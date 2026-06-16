#include<bits/stdc++.h>
using namespace std;

int n;
int arr[105][105];
vector<int> adj[105];
vector<int> lt[105];
bool visited[105];

void bfs(int u, int cnt)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    lt[cnt].push_back(u);

    while(!q.empty())
    {
        int x = q.front(); q.pop();
        for(auto v : adj[x])
        {
            if(!visited[v])
            {
                lt[cnt].push_back(v);
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    for(int i= 1; i<= n; i++)
    {
        for(int j = 1; j<= n;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j])
                adj[i].push_back(j);
        }
    }

    int cnt = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i<= n; i++)
    {
        if(!visited[i])
        {
            ++cnt;
            bfs(i,cnt);
        }   
    }

    cout << cnt <<"\n";
    for(int i = 1; i<= cnt; i++)
    {
        sort(lt[i].begin(), lt[i].end());
        for(auto x : lt[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}