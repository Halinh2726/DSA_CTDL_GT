#include<bits/stdc++.h>
using namespace std;

int n;
int arr[105][105];
vector<pair<int,int>> dsk;
vector<int> adj[105];
bool visited[105];

void dfs(int u)
{
    visited[u] = true;
    
    for(int x : adj[u])
    {
        if(!visited[x])
        {
            dfs(x);
        }
    }
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty())
    {
        int x = q.front(); q.pop();
        
        for(int u : adj[x])
        {
            if(!visited[u])
            {
                q.push(u);
                visited[u] = true;
            }
        }
    }
}

// int cnt_lt(int u,int v)
// {
//     memset(visited, false, sizeof(visited));
//     int cnt = 0;
//     for(int i = 1; i<= n; i++)
//     {
//         if(!visited[i]
//         {
//             dfs(u,v);
//             bfs(u,v);
//             cnt++;
//         })
//     }
//     return cnt;
// }

bool component()
{
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for(int i =1 ; i<= n; i++)
    {
        if(!visited[i])
        {
            ++cnt;
            if(cnt > 1) return false;
            dfs(i);
        }
    }
    return true;
}

int euler()
{
    if(!component()) return 0;
    int start = 0;
    int end = 0;
    for(int i= 1; i<= n; i++)
    {
        if(== 1) start++;
        else if( df)end++;
        else return 0;
    }

    if(start == 0 && end == 0) return 1;
    else if(start == 1 && end == 1) return 2;
    else return 0;
}

int main()
{
    int t;
    cin >> t;
    cin >> n;
    int cnt[105];
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            cin >>arr[i][j];
            if(arr[i][j])
            {
                cnt[i] += arr[i][j];
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }


    if(t==1)
    {
        for(int i = 1; i<= n; i++)
        {
            cout << cnt <<"\n";
        }
    }

    if(t==2)
    {

    }

    int u; cin >>u;
    stack<int> st;
    st.push(u);
    int tmp = u;

    vector<int> res;
    res.reserve(n+1);
    while(!st.empty())
    {
        if(st.size() > 0)
        {
            tmp = st.top();
        }

        bool hadEdge = false;
        for(int i = 1; i<= n; i++)
        {
            if(arr[tmp][i])
            {
                st.push(i);
                arr[tmp][i] = 0;

                hadEdge = true;
                break;
            }
        }
        if(!hadEdge)
        {
            res.push_back(tmp);
            st.pop();
        }
    }
}

#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[105][105];
vector<int> dsk[105];
vector<pair<int,int>> adj;
bool taken[105];
int ans;
vector<pair<int,int>> res[105];

void prim(int m)
{
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
    taken[m] = true;

    while(!q.empty())
    {
        pair<int, pair<int,int>> tmp = q.top(); q.pop();
        int u = tmp.second.first;
        int v = tmp.second.second;
        int weight = tmp.first;

        if(!taken[v])
        {
            taken[v] =true;
            ans += weight;
            adj->push_back({min(u,v), max(u,v)});

            for(auto x : res[v])
            {
                if(!taken[x.second])
                {
                    q.push({x.first, {v,x.second}});
                }
            }
        }
    }
    cout << ans << "\n";
    for(auto x : adj)
    {
        cout << x.first << " " << x.second << " " << arr[x.fist][x.second]
;    }
}