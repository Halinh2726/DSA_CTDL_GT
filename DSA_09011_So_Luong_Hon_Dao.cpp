#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[505][505];
bool visited[505][505];

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void dfs(int i, int j)
{
    visited[i][j] = true;

    for(int k = 0; k< 8; k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if(ni >= 0 && ni < n && nj >= 0 && nj < m)
        {
            if(a[ni][nj] == 1 && !visited[ni][nj])
            {
                dfs(ni,nj);
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
        cin >> n >> m;

        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                visited[i][j] = false;
            }
        }

        int cnt = 0;
        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j< m; j++)
            {
                if(a[i][j] == 1 && !visited[i][j])
                {
                    dfs(i,j);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}