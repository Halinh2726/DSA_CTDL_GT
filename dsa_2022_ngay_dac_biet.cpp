#include<bits/stdc++.h>
using namespace std;

int a[10];

void inkq()
{
    string s ="";
    for(int i = 1; i<= 8; i++)
    {
        if(a[i] == 1)
        {
            a[i] = 2;
        }
        if(i==3 || i==5)
        {
            s += '/';
        }
        s += a[i] + '0';
    }
    cout << s;
    cout << "\n";
}
int cnt = 0;
void Try(int i)
{
    // 0: 0, 1:2
    cnt++;
    for(int j = 0; j<= 1; j++)
    {
        if(i == 2 && j == 0 && a[1] == 0)
            continue;
        if(i== 5 && j == 0) continue;

        if(i == 3 && j == 1) continue;
        if(i==4 && j == 0) continue;
        a[i] = j;
        if(i==8)
        {
            inkq();
        }
        else
        {
            Try(i+1);
        }
    }
}
int main()
{
    Try(1);
    // cout << cnt <<"\n";
}