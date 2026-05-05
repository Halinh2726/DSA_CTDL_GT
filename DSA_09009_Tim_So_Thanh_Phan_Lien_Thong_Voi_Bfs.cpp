#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int v,e;
bool visited[MAXN];
int parent[MAXN];
vector<int> adj[1001];

void chuyen_ds_canh_sang_ds_ke()
{
    cin >> v >> e;
    for(int i = 0; i< e; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }    
}

void reset()
{
    for(int i = 0; i< MAXN; i++)
    {
        adj[i].clear();
        visited[i] = false;
    }
}

void bfs(int u, vector<int>& component)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        component.push_back(u); // Lưu tất cả thành phần liên thông // gom đỉnh vào nhóm

        for(int x: adj[u])
        {
            if(!visited[x])
            {
                visited[x] = true;
                q.push(x);
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
        reset();
        chuyen_ds_canh_sang_ds_ke();

        vector<vector<int>> components;

        for(int i=1; i<= v; i++)
        {
            if(!visited[i])
            {
                vector<int> component; 
                bfs(i,component);
                sort(component.begin(), component.end());
                components.push_back(component);
            }
        }
        cout << components.size() << "\n";
    }
}