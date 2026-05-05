#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
bool visited[1001];
void dfs(int u)
{
	visited[u] = true;
	for(auto v: adj[u])
	{
		if(!visited[v])
		{
			dfs(v);
		}
	}
}

void chuyendscanhsangdske()
{
	for(int i = 0; i< m; i++)
	{
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void reset()
{
	for(int i = 1; i<= n; i++)
	{
		adj[i].clear();
	}	
	memset(visited, false, sizeof(visited));
}

void dinhtru()
{
	int ans = 0; // dem so luong dinh tru
	int tplt = 0; // dem so tplt truoc khi loai bo dinh i
	memset(visited, false, sizeof(visited));
	for(int i = 1; i<= n;i++)
	{
		if(!visited[i])
		{
			++tplt;
			dfs(i);
		}
	}
	for(int i= 1; i<= n; i++)
	{
		// loai bo dinh i
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		int cnt = 0; // dem so luong tplt sau khi loai bo dinh i
		for(int j= 1; j<= n; j++)
		{
			if(!visited[j])
			{
				++cnt;
				dfs(j);
			}
		}
		if(cnt > tplt)
		{
			cout << i << " ";
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
		reset();
		chuyendscanhsangdske();
		dinhtru();	
        cout << "\n";
	}
	return 0;
}