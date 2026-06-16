#include<bits/stdc++.h>
using namespace std;

int n,u,t;
int arr[105][105];
vector<int> degIn(101,0), degOut(101,0);
vector<int> dsk[105];
vector<pair<int,int>> adj;
vector<pair<int,int>> bridges;
bool visited[105];

void dfs(int u)
{
    visited[u] = true;
    for(int x : dsk[u])
    {
        if(!visited[x])
        {
            dfs(x);
            visited[x] = true;
        }
    }
}

bool iscomponent()
{
    memset(visited,false, sizeof(visited));
    int cnt = 0;
    for(int i =1; i<= n; i++)
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

int iseuler()
{
    if(!iscomponent()) return 0;

    int start = 0;
    int end = 0;
    for(int i = 1; i<= n; i++)
    {
        if(degIn[i] - degOut[i] == 1)  start++;
        else if(-degIn[i]+degOut[i] == 1) end++;
        else if(degIn[i] != degOut[i]) return 0; 
    }

    if(start == 0 && end == 0) return 1;
    else if(start == 1 && end == 1) return 2;
    return 0;
}

int main()
{
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);
    cin >> t;
    memset(visited, false, sizeof(visited));
    if(t==1)
    {
        cin >> n;
        for(int i = 1; i<= n; i++)
        {
            for(int j = 1; j<= n; j++)
            {
                cin >> arr[i][j];
            }
        }

        for(int i =1 ; i<= n; i++)
        {
            for(int j = 1; j<= n; j++)
            {
                if(arr[i][j])
                {
                    ++degOut[i];
                    ++degIn[j];
                    dsk[i].push_back(j);
                    adj.push_back({i,j});
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
            for(int j = 1; j <= n;j++)
                cin >> arr[i][j];
        }
        stack<int> st;
        st.push(u);
        int tmp = u;

        vector<int> res;
        while(!st.empty())
        {
            tmp = st.top();

            bool hasEdge = false;
            for(int i = 1; i<= n; i++)
            {
                if(arr[tmp][i])
                {
                    st.push(i);

                    arr[tmp][i] = 0;

                    hasEdge = true;
                    break;
                }
            }

            if(!hasEdge)
            {
                res.push_back(tmp);
                st.pop();
            }
        }
        reverse(res.begin(), res.end());
        for(int x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}

