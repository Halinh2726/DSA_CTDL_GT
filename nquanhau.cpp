#include<bits/stdc++.h>
using namespace std;

int n;
int p[20], visited[20];
int ans = 0;
int step = 0;

int kiemtra()
{
    for(int i = 1; i<= n; i++)
    {
        for(int j = i+1; j<= n;j++)
        {
            if(i - p[i] == j - p[j]|| i+p[i] == j + p[j])
            {
                return 0;
            }
        }
    }
}
void backtrack(int pos)
{
    if(pos > n)
    {
        step++;
        if(kiemtra())
        {
            ans++;
        }
    }
}