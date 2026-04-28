#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        
        vector<string> res(n);
        for(int i = 0; i< n; i++)
        {
            cin >> res[i];
        }

        int a,b,c,d;
        cin >> a >> b >> c >> d;

        if(a==c && b == d)
        {
            cout << 0 << "\n";
            continue;
        }

        vector<vector<int>> dist(n,vector<int>(n,-1)); // Ma tran nxn co gia tri la -1
        queue<pair<int, int>> q;

        dist[a][b] = 0;
        q.push({a,b});

        bool check = false;
        while(!q.empty() && !check)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i< 4; i++)
            {
                int u = x + dx[i];
                int v = y + dy[i];

                while(u >= 0 && u < n && v >= 0 && v<n && res[u][v] != 'X')
                {
                    if(dist[u][v] == -1)
                    {
                        dist[u][v] = dist[x][y] + 1;
                        q.push({u,v});

                        if(u == c && v ==d)
                        {
                            check = true;
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                    u += dx[i];
                    v += dy[i];
                }
            }
        }
        cout << dist[c][d] << "\n";
    }
    return 0;
}