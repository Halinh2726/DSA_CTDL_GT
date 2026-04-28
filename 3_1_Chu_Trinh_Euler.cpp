// #include<bits/stdc++.h>
// using namespace std;

// int n, u;
// bool visited[105];
// int a[105][105];
// vector<int> adj[105];

// void chuyen_matrix_sang_ds_ke()
// {
//     for(int i = 1; i<= n; i++)
//     {
//         for(int j = 1; j<=  n; j++)
//         {
//             if(a[i][j])
//             {
//                 adj[i].push_back(j);
//             }
//         }
//     }
// }

// void dfs(int u)
// {
//     visited[u] = true;
//     for(int i = 1; i<= n; i++)
//     {
//         if(!visited[i])
//         {
//             dfs(i);
//         }
//     }
// }

// bool isconnect()
// {
//     memset(visited, false, sizeof(visited));

//     int s = -1;
//     for(int i = 1; i<= n; i++)
//     {
//         int deg = 0;
//         for(int j = 1; j<= n; j++)
//             deg += a[i][j];
//         if(deg > 0)
//         {
//             s = i;
//             break;
//         }
//     }

//     if(s == -1) return true;

//     dfs(s);

//     for(int i = 1; i<= n; i++)
//     {
//         int deg = 0;
//         for(int j = 1; j<= n; j++)
//             deg += a[i][j];
//         if(deg >0 && !visited[i])
//             return false;
//     }
//     return true;
// }

// int main()
// {
//     // freopen("CT.INP", "r", stdin);
//     // freopen("CT.OUT", "w", stdout);

//     int t;
//     cin >> t;
//     if(t== 1)
//     {
//         cin >> n;
//         for(int i = 1; i<= n; i++)
//         {
//             for(int j = 1; j<= n; j++)
//             {
//                 cin >> a[i][j];
//             }
//         }

//         chuyen_matrix_sang_ds_ke();
//         if(!isconnect())
//         {
//             cout << 0;
//             return 0;
//         }

//         int odd = 0;
//         for(int i = 1; i <= n; i++)
//         {
//             int deg = 0;
//             for(int j = 1; j<= n; j++)
//             {
//                 deg += a[i][j];
//             }
//             if(deg % 2 != 0) odd++;
//         }

//         if(odd == 0) cout << 1;
//         else if(odd == 2) cout << 2;
//         else cout << 0;
//     }
//     else 
//     {
//         cin >> n >> u;
//         for(int i = 1; i<= n;i++)
//             for(int j = 1; j<= n; j++)
//                 cin >> a[i][j];
//         chuyen_matrix_sang_ds_ke();
//         stack<int> st;
//         vector<int> path;

//         st.push(u);

//         while(!st.empty())
//         {
//             int x = st.top();
//             bool found = false;

//             for(int i = 1; i<= n; i++)
//             {
//                 if(a[x][i])
//                 {
//                     st.push(i);
//                     a[x][i] = a[i][x] = 0;
//                     found = true;
//                     break;
//                 }
//             }

//             if(!found)
//             {
//                 path.push_back(x);
//                 st.pop();
//             }
//         }
//         reverse(path.begin(), path.end());

//         for(int x : path)
//             cout << x << " ";
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int n, u;
bool visited[105];
int a[105][105];

void dfs(int u)
{
    visited[u] = true;
    for(int i = 1; i <= n; i++)
    {
        if(a[u][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

bool isconnect()
{
    memset(visited, false, sizeof(visited));

    int s = -1;
    for(int i = 1; i<= n; i++)
    {
        int deg = 0;
        for(int j = 1; j<= n; j++)
            deg += a[i][j];
        if(deg > 0)
        {
            s = i;
            break;
        }
    }

    if(s == -1) return true;

    dfs(s);

    for(int i = 1; i<= n; i++)
    {
        int deg = 0;
        for(int j = 1; j<= n; j++)
            deg += a[i][j];
        if(deg > 0 && !visited[i])
            return false;
    }
    return true;
}

int main()
{
freopen("CT.INP", "r", stdin);
freopen("CT.OUT", "w", stdout);

    int t;
    cin >> t;

    if(t == 1)
    {
        cin >> n;
        for(int i = 1; i<= n; i++)
            for(int j = 1; j<= n; j++)
                cin >> a[i][j];

        if(!isconnect())
        {
            cout << 0;
            return 0;
        }

        int odd = 0;
        for(int i = 1; i <= n; i++)
        {
            int deg = 0;
            for(int j = 1; j<= n; j++)
                deg += a[i][j];
            if(deg % 2 != 0) odd++;
        }

        if(odd == 0) cout << 1;
        else if(odd == 2) cout << 2;
        else cout << 0;
    }
    else
    {
        cin >> n >> u;
        for(int i = 1; i<= n;i++)
            for(int j = 1; j<= n; j++)
                cin >> a[i][j];
        
        stack<int> st;
        vector<int> path;

        st.push(u);

        while(!st.empty())
        {
            int x = st.top();
            bool found = false;

            for(int i = 1; i<= n; i++)
            {
                if(a[x][i])
                {
                    st.push(i);
                    a[x][i] = a[i][x] = 0;
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                path.push_back(x);
                st.pop(); // FIX
            }
        }

        reverse(path.begin(), path.end());

        for(int x : path)
            cout << x << " ";
    }
    return 0;
}