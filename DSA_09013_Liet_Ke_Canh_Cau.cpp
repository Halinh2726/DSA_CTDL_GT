#include<bits/stdc++.h>
using namespace std;
/*
1. Dùng một vector<pair<int, int>> dscanh để lưu lại các cạnh của đồ thị
2. Dùng một hàm gọi dfs tuy nhiên bao gồm cả 2 đỉnh của cạnh mà không được duyệt vào(vì xóa cạnh đó để kiểm tra xem có là cạnh cầu hay không)
    dfs2(int i, int s, int t)
3. Đếm số thành phần liên thông 
4. Duyệt các cạnh trong dscanh sau đó gọi hàm dfs2 để đếm lại số thành phần liên thông,
    Nếu lớn hơn thì in ra cạnh đó
*/
int n,m;
vector<int> adj[1001];
bool visited[1001];
vector<pair<int,int>> dscanh;

void chuyendscanhsangdske()
{
	for(int i = 0; i< m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		dscanh.push_back({x,y});
	}
}
void reset()
{
	for(int i= 1; i<= n; i++)
	{
		adj[i].clear();
	}
	dscanh.clear();
	memset(visited, false, sizeof(visited));
}
void dfs(int i)
{
	visited[i] = true;
	for(int u : adj[i])
	{
		if(!visited[u])
		{
			dfs(u);
			visited[u] = true;
		}
	}
}
void dfs2(int u, int s, int t)
{
	// s,t khong bao h duoc duyet vao
	visited[u] = true;
	for(int v: adj[u])
	{
		if((u == s && v == t) || (u==t && v == s)) continue;
		if(!visited[v]) dfs2(v,s,t);
	}
}

void canhcau()
{
	// dem so thanh phan lien thong
	int ans = 0;
	int tplt = 0;
	memset(visited, false, sizeof(visited));
	for(int i = 1; i<= n; i++)
	{
		if(!visited[i])
		{
			++tplt;
			dfs(i);
		}
	}
	vector<pair<int,int>> res;
	for(auto it: dscanh)
	{
		int x = it.first;
		int y = it.second;
		// Loai bo canh x,y khoi do thi
		memset(visited, false, sizeof(visited));
		int cnt = 0;
		for(int j = 1; j<= n;j++)
		{
			if(!visited[j])
			{
				++cnt;
				dfs2(j,x,y);
			}
		}
		if(cnt > tplt)
		{
            // ++ans;
			cout << x << " " << y << " "; 
		}
	}
	//cout << ans << "\n";
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
		canhcau();
		cout << "\n";
	}
	return 0;
}