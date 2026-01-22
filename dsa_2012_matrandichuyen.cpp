#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200][200];
vector<int> tmp;
int cnt;

void backtrack(int i, int j)
{
    if(i>= n || j>= m)
        return;
    
    if(i == n-1 && j == m-1)
    {
        cnt++;
        return;
    }

    backtrack(i+1,j);
    backtrack(i,j+1);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        for(int i=0; i<m; i++)
        {
            for(int j =0;j< n;j++)
            {
                cin >> a[i][j];
            }
        }

        cnt = 0;
        backtrack(0,0);
        cout << cnt << "\n";
    }
    return 0;
}