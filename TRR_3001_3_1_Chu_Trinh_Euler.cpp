#include<bits/stdc++.h>
using namespace std;

int t,n,u;
int arr[105][105];
vector<int> adj[105];
vector<int> deg(105,0);
bool visited[105];

void dfs(int u)
{
    visited[u] = true;
    for(int v : adj[u])
    {
        if(!visited[v]) dfs(v);
    }
}

bool is_component()
{
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for(int i= 1; i<= n; i++)
    {
        if(!visited[i])
        {
            cnt++;
            if(cnt > 1) return false;
            dfs(i);
        }
    }
    return true;
}

int iseuler()
{
    if(!is_component()) return 0;

    int odd = 0;
    for(int i =1; i<= n; i++)
    {
        if(deg[i] % 2 == 1) ++odd;
    }

    if(odd == 0) return 1; // chu trinh 
    else if(odd == 2) return 2; // duong di
    return 0;
}
int main()
{
    //freopen("CT.INP", "r", stdin);
    //freopen("CT.OUT", "w", stdout);
    int t; cin >> t;
    if(t == 1)
    {
        cin >> n;

    for(int i = 1; i<= n; i++)
        for(int j = 1; j<= n; j++)
            cin >> arr[i][j];

    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            if(arr[i][j])
            {
                ++deg[i];
                adj[i].push_back(j);
            }
        }
    }
    
        cout << iseuler() << "\n";
    }
    
    if(t==2)
    {
        cin >> n >> u;
        for(int i = 1; i<= n; i++)
        {
            for(int j = 1; j<= n; j++)
                cin >> arr[i][j];
        }

        stack<int> st;
        st.push(u);
        int cur = u;

        vector<int> res;
        while(!st.empty())
        {
            cur = st.top();
            bool hasEdge = false;
            for(int i= 1; i<= n; i++)
            {
                if(arr[cur][i])
                {
                    st.push(i);

                    arr[cur][i] = 0;
                    arr[i][cur] = 0;

                    hasEdge = true;
                    break;
                }
            }
            if(!hasEdge)
            {
                res.push_back(cur);
                st.pop();
            }
        }
        reverse(res.begin(), res.end());
        for(int x : res)
        {
            cout << x << " ";
        }
    }
    return 0;
}