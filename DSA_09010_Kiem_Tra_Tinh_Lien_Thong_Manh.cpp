#include<bits/stdc++.h>
using namespace std;
/*
Thuật Toán Kosaraju( 2 lan thuat toan dfs)
B1. Xây dựng dfs trên đồ thị gốc => lưu vào trong stack
B2. Xây dựng một đồ thị đảo của đồ thị gốc, transform graph
B3. In ra các thành phàn liên thông của mình
+ pop các đỉnh trong stack ở bước 1 và gọi dfs ở transform graph
*/
// strongly connected components: SCC

int n,m;
bool visited[1001];
vector<int> adj[1001], radj[1001] ; // radj luu đồ thị lật ngược
stack<int> st;

void chuyendscanhsangdske()	
{
	for(int i = 1; i<= m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		radj[y].push_back(x); //  Xay dung do thi lat nguoc
	}
}

void reset()
{
	for(int i = 1; i<= n; i++)
	{
		adj[i].clear();
		radj[i].clear();
	}
	memset(visited, false, sizeof(visited));
	while(!st.empty()) st.pop(); 
}

void dfs1(int u)
{
	visited[u] = true;
	for(int v : adj[u])
	{
		if(!visited[v])
			dfs1(v);
	}
	st.push(u);
}

void dfs2(int u)
{
	visited[u] = true;
	// cout << u << " "; 
	for(int v : radj[u])
	{
		if(!visited[v])
		{
			dfs2(v);
		}
	}
}
// Liet ke hoặc đếm cac thanh phan lien thong manh
void scc(){
	memset(visited, false, sizeof(visited));
	// Goi thuat toan dfs tren do thi ban dau
	for(int i = 1; i<= n; i++)
	{
		if(!visited[i])
		{
			dfs1(i);
		}
	}
	
	// Buoc 3: Lat nguoc dinh trong stack va dfs2
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	
	while(!st.empty())
	{
		int u = st.top();
		st.pop();
		if(!visited[u])
		{
			dfs2(u);
//			cout << "\n";
			cnt++;
		}
	}
	if(cnt == 1) cout << "YES\n";
	else cout << "NO\n";
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
		scc();
		cout << "\n";
	}
}