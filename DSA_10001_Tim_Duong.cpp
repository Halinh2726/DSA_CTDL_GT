#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int x, y;
    int dir;
    int turn;
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        vector<string> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int sx, sy, tx, ty;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }

                if (a[i][j] == 'T')
                {
                    tx = i;
                    ty = j;
                }
            }
        }

        vector<vector<vector<int>>> visited(
            n,
            vector<vector<int>>(m, vector<int>(4, 1e9))
        );

        queue<Node> q;

        for (int d = 0; d < 4; d++)
        {
            visited[sx][sy][d] = 0;
            q.push({sx, sy, d, 0});
        }

        bool ok = false;

        while (!q.empty())
        {
            Node cur = q.front();
            q.pop();

            int x = cur.x;
            int y = cur.y;
            int dir = cur.dir;
            int turn = cur.turn;

            if (x == tx && y == ty)
            {
                ok = true;
                break;
            }

            for (int nd = 0; nd < 4; nd++)
            {
                int nx = x + dx[nd];
                int ny = y + dy[nd];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                if (a[nx][ny] == '*')
                    continue;

                int newTurn = turn;

                if (nd != dir)
                    newTurn++;

                if (newTurn > 2)
                    continue;

                if (visited[nx][ny][nd] > newTurn)
                {
                    visited[nx][ny][nd] = newTurn;
                    q.push({nx, ny, nd, newTurn});
                }
            }
        }

        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}