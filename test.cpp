#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
bool visited[1001];

void dfs(int u)
{
    cout << u << " ";
    visited[u] = true;
    for(auto x: adj[u])
    {
        if(!visited[x])
            dfs(x);
    }
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(auto i : adj[v])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int a[1001][1001];
void c1()
{
    // Danh sach ke sang ma tran ke
    cin >> n >> m;
    for(int i = 0; i< m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }  
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= n;j++)
        {
            cout << a[i][j] <<" ";
        }
        cout << "\n";
    } 
}

vector<int> tmp[1001];
void c2()
{
    // Danh sach canh sang danh sach ke
    cin >> n >> m;
    for(int i= 0;i< m; i++)
    {
        int x, y;
        cin >> x  >> y;
        tmp[x].push_back(y);
        tmp[y].push_back(x);
    }
    for(int i = 1;i <= n; i++)
    {
        cout << i << ": ";
        for(auto x: adj[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

void c3()
{
    // Danh sach ke sang danh sach canh
    vector<pair<int, int>> edge;
    vector<int> cnt[1001];
    cin >> n;
    cin.ignore();
    for(int i = 1; i<= n; i++)
    {
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while(ss >> num)
        {
            if(stoi(num) > i)
            {
                edge.push_back({i, stoi(num)});
            }
        }
    }
}

void c4()
{
    // matix ke sang danh sach ke
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= m; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i =1; i<= n; i++)
    {
        for(int j = 1; j<= m; j++)
        {
            if(a[i][j])
                adj[i].push_back(j);
        }
    }

    for(int i = 1; i<= n; i++)
    {
        cout << i << ": ";
        for(auto x : adj[i])
        {
            cout << x << " ";
        }
        cout <<"\n";
    }
}

void c5()
{
    // matrix ke sang ds canh
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= m; j++)
        {
            cin >> a[i][j];
        }
    }
 vector<pair<int, int>> edge;
    for(int i = 1; i<= n; i++)
    {
        for(int j= 1; j<= m; j++)
        {
            if(a[i][j])
                edge.push_back({i,j});
        }
    }

    for(auto x : edge)
    {
        cout << x.first << " "<< x.second;
        cout << "\n";
    }
}