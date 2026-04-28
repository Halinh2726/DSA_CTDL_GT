#include<bits/stdc++.h>
using namespace std;

const int maxn = 10010;
/*
Cho đồ thị vô hướng có N đỉnh (1 <= N <= 10^4) và M cạnh (1 <= M <= 10^5). Một đỉnh được gọi là khớp nếu như xóa đỉnh đó đi sẽ làm tăng số lượng thành phần liên thông của đồ thị. Một cạnh được gọi là cạnh cầu nếu như xóa cạnh đó đi sẽ làm tăng số lượng thành phần liên thông của đồ thị.

Nhiệm vụ của bạn là hãy đếm số lượng khớp và cầu của đồ thị đã cho.

wO4VSAsY8cAowAAAABJRU5ErkJggg==

Input:

Dòng đầu tiên hai số nguyên N và M.

M dòng tiếp theo, mỗi dòng gồm hai số nguyên u, v cho biết có cạnh nối giữa đỉnh u và v.

Output: 

In ra 2 số nguyên là số lượng khớp và cầu của đồ thị

Test ví dụ:

Input:

Output

10 12

1 10

10 2

10 3

2 4

4 5

5 2

3 6

6 7

7 3

7 8

8 9

9 7

4 3

 
*/
int n,m;
bool check[maxn];
int timeDfs = 0, bridge = 0;
int low[maxn], num[maxn];
vector<int> adj[maxn];

void dfs(int n, int pre)
{
    int con = 0;
    num[n] = low[n] = ++timeDfs;
    for(auto v : adj[n])
    {
        if(v != pre)
        {
            if(!num[v])
            {
                dfs(v,n);
                low[n] = min(low[n], low[v]);
                if(low[v] == num[v]) bridge++;
                con++;
                if(n == pre)
                {
                    if(con > 1) check[n] = true;
                }
                else if(low[v] >= num[n]) check[n] = true;
            }
            else
            {
                low[n] = min(low[n], num[v]);
            }
        }
    }
    // tail[n] = timeDfs;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i<= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i<= n; i++)
    {
        if(!num[i]) dfs(i,i);
    }
    int cnt = 0;
    for(int i = 1; i<= n; i++) cnt += check[i];
    cout << cnt << " " << bridge;
    return 0;
}