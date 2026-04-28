#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<string> a;
bool danger[4][105][105];
bool visited[105][105][4];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int check(char c)
{
    if(c == '^') return 0;
    if(c == '>') return 1;
    if(c == 'v') return 2;
    if(c == '<') return 3;
    return -1;
}
void builddanger()
{
    memset(danger, false, sizeof(danger));
    memset(visited, false, sizeof(visited));

    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int tmp = check(a[i][j]);
            if(tmp == -1) continue;

            for(int t = 0; t < 4; t++)
            {
                int nd = (tmp + t) %4;

                int x = i + dx[nd];
                int y = j + dy[nd];

                while(x >= 0 && x < n && y >= 0 && y <m)
                {
                    if(a[x][y] == '#' || check(a[x][y]) != -1)
                        break;
                    danger[t][x][y] = true;

                    x += dx[nd];
                    y += dy[nd];
                }
            }
        }
    }
}

int bfs(pair<int, int> s, pair<int, int> g)
{
    memset(visited, false, sizeof(visited));
    queue<tuple<int,int,int,int>> q;

    if(danger[0][s.first][s.second]) return -1;

    q.push({s.first, s.second, 0,0});
    visited[s.first][s.second][0] = true;

    
    while(!q.empty())
    {
        auto [x,y,t,dist] = q.front();
        q.pop();

        if(danger[t][x][y]) continue;
        if(x == g.first && y == g.second)
            return dist;

        int nt = (t + 1) % 4;

        for(int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(a[nx][ny] == '#') continue;

            if(danger[nt][nx][ny]) continue;

            if(!visited[nx][ny][nt])
            {
                visited[nx][ny][nt] = true;
                q.push({nx, ny, nt, dist + 1});
            }
        }
    }
    return -1;
}
void solve()
{
    cin >> n >> m;
    a.resize(n);

    pair<int, int> s,g;

    for(int i = 0; i< n; i++)
    {
        cin >> a[i];
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == 'S') s = {i,j};
            if(a[i][j] == 'G') g = {i,j};
        }
    }

    builddanger();
    int ans = bfs(s,g);
    if(ans == -1) cout << "impossible\n";
    else cout << ans <<"\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}

