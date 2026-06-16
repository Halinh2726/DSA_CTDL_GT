#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1005];
bool visited[1005];
int parent[1005];
vector<int> cy;

void chuyendscanhsangdske()
{
    for(int i = 1; i<=m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
}

void reset()
{
    for(int i = 1; i<= n; i++)
    {
        adj[i].clear();
    }
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    
    cy.clear();
}

bool dfs(int u, int par)
{
    visited[u] = true;
    
    for(auto x: adj[u])
    {
        if(!visited[x])
        {
            parent[x] = u;
            if(dfs(x,u)){
                return true;
            }
        }
        else if(x != par)
        {
            cy.push_back(x);

            int cur = u;

            while(cur != x)
            {
                cy.push_back(cur);
                cur = parent[cur];
            }
            cy.push_back(x);
            reverse(cy.begin(),cy.end());

            return true;
        }
    }
    return false;
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        int ok = 0;
        reset();
        chuyendscanhsangdske();
        
        if(dfs(1,0))
        {
            for(auto x : cy)
            {
                cout << x << " ";
            }
            cout << "\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}