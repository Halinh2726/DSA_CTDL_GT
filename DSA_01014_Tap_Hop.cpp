#include<bits/stdc++.h>
using namespace std;

int n, k, s;
int a[25];
int cnt;

void inkq()
{
    int dem = 0, sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i])
        {
            dem++;
            sum += i;
        }
    }
    if(dem == k && sum == s) cnt++;
}

void backtrack(int i)
{
    // nếu đã xét hết
    if(i > n)
    {
        inkq();
        return;
    }

    // 0: không chọn i
    a[i] = 0;
    backtrack(i + 1);

    // 1: chọn i
    a[i] = 1;
    backtrack(i + 1);
}

int main()
{
    while(true)
    {
        cin >> n >> k >> s;
        if(n == 0 && k == 0 && s == 0) break;

        cnt = 0;
        backtrack(1);

        cout << cnt << endl;
    }
}