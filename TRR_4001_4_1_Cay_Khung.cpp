    #include<bits/stdc++.h>
    using namespace std;

    int nhap,n,m;
    vector<int> adj[105];
    vector<int> parent[105];
    bool visited[105];
    int c[105][105];
    vector<pair<int,int>> tmp;

    void input()
    {
        cin >> nhap;
        cin >> n >> m;
        for(int i = 1; i<= n; i++)
        {
            for(int j = 1; j<= n;j++)
                cin >> c[i][j];
        }
        memset(visited, false, sizeof(visited));
    }

    void chuyenmatrankesangdske()
    {
        for(int i = 1; i<= n; i++)
            for(int j = 1; j<= n; j++)
                if(c[i][j] == 1)
                    adj[i].push_back(j);
    }

    void dfs(int m)
    {
        visited[m] = true;
        
        for(int x : adj[m])
        {
            if(!visited[x])
            {
                tmp.push_back({m,x});
                dfs(x);
            }
        }
    }

    void bfs(int s)
    {
        queue<int> q;
        q.push(s);
        visited[s] = true;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(int v : adj[u])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    tmp.push_back({u, v});
                    q.push(v);
                }
            }
        }
    }
    int main()
    {
        // freopen("CK.INP", "r", stdin);
        // freopen("CK.OUT", "w", stdout);
        input();
        chuyenmatrankesangdske();
        if(nhap == 1)
        {
            dfs(m);   
        }
        else if(nhap == 2)
        {
            bfs(m);
        } 
        
        if(tmp.size() == n-1)
        {
            cout << tmp.size() << "\n";
            for(int i = 0; i< tmp.size(); i++)
            {
                cout << min(tmp[i].first, tmp[i].second) << " "
                    << max(tmp[i].first, tmp[i].second) << "\n";
            }
        }
        else
        {
            cout << "0\n";
        }

        return 0;
    }
