#include<bits/stdc++.h>
using namespace std;

int n;
long long cnt;
int c[10], d1[30], d2[30];

void backtrack(int row)
{
    if(row == n)
    {
        cnt++;
        return;
    }
    for(int col = 0; col < n; col++)
    {
        if(!c[col] && !d1[row-col+n] && !d2[col + row])
        {
            c[col] = d1[row-col+n] = d2[row+col] = 1;
            backtrack(row + 1);
            c[col] = d1[row-col+n] = d2[row+col] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n; 
        cnt = 0;
        memset(c,0,sizeof(c));
        memset(d1,0,sizeof(d1));
        memset(d2,0,sizeof(d2));
        backtrack(0);
        cout << cnt << "\n";
    }
    return 0;
}