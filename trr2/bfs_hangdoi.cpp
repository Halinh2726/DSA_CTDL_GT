#include<bits/stdc++.h>
using namespace std;
/*
1. Khoi tao hang doi rong, push dinh dau tien vao hang doi.
2. Duy tri mang danh dau xem da duoc tham hay chua
3. Lap den khi  hang doi rong, lay dinh dau hang doi. Tien hanh tham hang doi
*/

/*
10 11
1 2
1 3 
1 5
1 10
2 4
3 6
3 7
3 9
6 7
5 8
8 9
*/

int n,m;
vector<int> adj[1001];
bool visited[1001];

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int x: adj[v])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i< m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    bfs(1);
}
