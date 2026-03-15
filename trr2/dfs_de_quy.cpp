#include<bits/stdc++.h>
using namespace std;
// Input: Danh sach canh
int n, m;
vector<int> adj[1001]; // Mang cac vector<> luu danh sach ke
bool visited[1001]; // Kiem tra da dc duyet qua ch

void dfs(int u)
{
    cout << u << " ";
    visited[u] = true;
    for(auto v : adj[u])
    {
        // Neu dinh v ch dc tham, goi dfs toi dinh v
        if(!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i< m ; i++)
    {// Chuyen ds canh sang ds ke
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // Bỏ dòng này nếu là đồ thị có hướng
    }
    memset(visited, false, sizeof(visited));
    dfs(1);
    return 0;
}