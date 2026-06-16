#include<bits/stdc++.h>
using namespace std;

int n;
int arr[105][105];
vector<int> dsk[105];
bool visited[105];
vector<int> adj;

void bfs(int u, int stop)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        if(x == stop) continue;

        for(int v : dsk[x])
        {
            if(!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int cntlt(int stop)
{
    int cnt = 0;
    memset(visited, false, sizeof(visited));
    if(stop) visited[stop] = true;
    for(int i = 1; i<= n; i++)
    {   
        if(!visited[i])
        {
            bfs(i,stop);
            ++cnt;
        }
    }
    return cnt;
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);    
    cin >> n;
    for(int i = 1; i<= n; i++)
        for(int j = 1; j<= n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j])
            {
                dsk[i].push_back(j);
            }
        }
    
    int cnt1 = cntlt(0);
    adj.reserve(n);
    memset(visited, false, sizeof(visited));

    for(int i= 1; i<= n; i++)
    {
        int tmp = cntlt(i);
        if(tmp > cnt1) 
            adj.push_back(i);
    }

    cout << adj.size() << "\n";
    for(auto x : adj)
    {
        cout << x << " ";
    }
    return 0;
}