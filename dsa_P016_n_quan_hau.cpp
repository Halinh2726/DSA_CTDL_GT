#include<bits/stdc++.h>
using namespace std;

int a[8][8];
bool c[8], d1[15], d2[15];
int tmp;

void backtrack(int row, int sum)
{
    if(row == 8)
    {
        tmp = max(tmp, sum);
        return;
    }
    for(int i = 0; i< 8; i++)
    {
        if(!c[i] && !d1[row - i +7] && !d2[row + i])
        {
            c[i] = d1[row-i+7] = d2[row+i] = true;
            backtrack(row+1, sum + a[row][i]);
            c[i] = d1[row - i + 7] = d2[row+i] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        for(int j = 0 ; j< 8; j++)
        {
            for(int m = 0; m< 8; m++)
            {
                cin >> a[j][m];
            }
        }
    memset(c, false, sizeof(c));
    memset(d1, false, sizeof(d1));
    memset(d2, false, sizeof(d2));
    tmp = 0;
    backtrack(0,0);
    cout << "Test " << i << ": " << tmp << "\n";
    }
    return 0;
}