#include<bits/stdc++.h>
using namespace std;

int n,s;
vector<int> adj[1001];
int a[1001][1001];
bool visited[1001];

void chuyen_matranke_sang_dske()
{
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<=  n; j++)
        {
            if(a[i][j])
            {
                adj[i].push_back(j);
            }
        }
    }
}
void dfs(int u)
{
    for(int i = 1; i<= n; i++)
    {
        if(!visited[i])
        {
            cout << u << " " << i << "\n";
            visited[i] = true;
            dfs(i);
        }        
    }
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        
        for(int i = 1; i<= n; i++)
        {
            if(!visited[i])
            {
                cout << x << " " << i << "\n";
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    cin >> n >> s;
    for(int i =1 ; i<= n; i++)
    {
        for(int j = 1; j<= n; j++)
            cin >> a[i][j];
    }   
    chuyen_matranke_sang_dske();

    // dfs
    cout << "DFS tree" << "\n";
    memset(visited, false, sizeof(visited));
    visited[s] = true;
    dfs(s);

    // khong lien thong
    for(int i = 1; i<= n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            dfs(i);
        }
    }

    //bfs
    cout << "BFS tree" << "\n";
    memset(visited, false, sizeof(visited));
    bfs(s);

    for(int i = 1; i<= n; i++)
    {
        if(!visited[i])
            bfs(i);
    }

    return 0;
}