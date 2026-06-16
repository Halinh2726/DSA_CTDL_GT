#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[105][105];
vector<pair<int,int>> adj;
bool token[105];
int ans;
vector<pair<int, int>> res[105];

void Prim(int m)
{
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, 
                    greater<pair<int,pair<int,int>>>> q;

    token[m] = true;

    for(pair<int, int> x : res[m])
    {
        if(!token[x.second])
        {
            q.push({x.first, {m, x.second}});
        }
    }

    while(!q.empty())
    {
        pair<int, pair<int,int>> tmp = q.top(); q.pop();
        int u = tmp.second.first,
            v = tmp.second.second,
            weight =tmp.first;
        
        if(!token[v])
        {
            token[v] = true;
            ans += weight;
            adj.push_back({min(u,v), max(u,v)});

            for(auto pa : res[v])
            {
                if(!token[pa.second])
                {
                    q.push({pa.first, {v, pa.second}});
                }
            }
        }
    }

    cout << ans <<"\n";
    for(auto x : adj)
    {
        cout << x.first << " "<< x.second << " "<< arr[x.first][x.second] <<"\n";
    }
}

int main()
{
        freopen("CK.INP", "r", stdin);
        freopen("CK.OUT", "w", stdout);
    cin >> n >> m;
    for(int i= 1; i<= n; i++)
        for(int j = 1; j<= n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] > 0 && arr[i][j] <= 50)
            {
                res[i].push_back({arr[i][j], j});
            }
        }
    
    memset(token, false, sizeof(token));
    Prim(m);
    return 0;
}