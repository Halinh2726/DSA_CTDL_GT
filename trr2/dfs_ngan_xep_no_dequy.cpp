#include<bits/stdc++.h>
using namespace std;

bool visited[105];
int main()
{
    int n;
    cin >> n;
    int adj[105][105];
    for(int i = 1; i<= n; i++)
        for(int j = 1; j<= n; j++)
            cin >> adj[i][j];
    memset(visited, false, sizeof(visited));
    
    stack<int> st;
    st.push(1);
    
    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        
        if(!visited[u])
        {
            cout << u  << " ";
            visited[u] = true;
            
            for(int i = n; i>= 1; i--)
            {
                if(adj[u][i] == 1 && !visited[i])
                {
                    st.push(i);
                }
            }
        }
    }
    return 0;
}