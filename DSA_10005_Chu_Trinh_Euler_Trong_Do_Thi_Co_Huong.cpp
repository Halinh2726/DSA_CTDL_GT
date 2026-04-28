#include<bits/stdc++.h>
using namespace std;

int indeg[1001], outdeg[1001];
int n,m;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        for(int i = 1; i <= n; i++)
        {
            indeg[i] = 0;
            outdeg[i] = 0;
        }

        for(int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            indeg[x]++;
            outdeg[y]++;
        }

        int odd = 1;
        for(int i = 1; i <= n; i++)
        {
            if(indeg[i] != outdeg[i])
            {
                odd = 0;
                break;
            }
        }

        // if(odd == 0) cout << 2 << "\n";
        if(odd) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}