#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
bool visited[1001];

void chuyendscanh()
{
	for(int i = 0; i< m;i++)
	{
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

bool dfs(int u, int par)
{
	visited[u] = true;
	for(auto x : adj[u])
	{
		if(!visited[x])
		{
			if(dfs(x,u)) return true;
		}
		else if(x != par)
		{
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
		for(int i = 1; i<= n; i++)
			adj[i].clear();
		chuyendscanh();
		for(int i = 1;i<= n;i++)
		{
			if(!visited[i])
			{
				if(dfs(i,0))
				{
					ok = 1;
                    break;
				}
			}
		}
        if(ok) cout << "YES\n";
        else cout << "NO\n";
	}
	return 0;
}