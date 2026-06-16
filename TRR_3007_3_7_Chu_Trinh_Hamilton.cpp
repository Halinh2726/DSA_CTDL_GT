#include<bits/stdc++.h>
using namespace std;

int n,u;
int arr[105][105];
int path[105];
bool visited[105];
int cnt;

void display()
{
    for(int i= 1; i<= n;i++)
    {
        cout << path[i] << " ";
    }
    cout <<path[1] << "\n";
    ++cnt;
}

void Hamilton(int k)
{
    for(int i= 1; i<= n; i++)
    {
        if(arr[path[k-1]][i] == 1)
        {
            if(k == n+1)
            {
                if(i == path[1])
                {
                    display();
                }
            }
            else
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    path[k] = i;

                    Hamilton(k+1);
                    visited[i]= false;
                }
            }
        }
    }
}

int main()
{
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> n >> u;
    for(int i = 1; i<= n; i++)
        for(int j = 1; j<= n; j++)
            cin >>arr[i][j];

    memset(visited, false, sizeof(visited));
    cnt = 0;
    visited[u]= true;
    path[1] = u;
    Hamilton(2);

    if(!cnt) cout << 0;
    else cout <<cnt;
    return 0;
}