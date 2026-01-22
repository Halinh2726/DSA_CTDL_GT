#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;
int cnt = 0;
int snt(int x)
{
    if(x < 2) return 0;
    for(int i = 2; i*i <= x; i++)
    {
        if(x%i == 0) return 0;
    }
    return 1;
}

void backtrack(int i)
{
    for(int j = a[i-1]+1; j<= n-k+i; j++)
    {
        a[i] = j;

        if(i == k)
    {
        cnt++;
        if(snt(cnt))
        {
            cout << cnt << ": ";
            for(int m = 1; m<= k ; m++)
            {
                cout << a[m] << " ";
            }
            cout << "\n";
        }
    }
    else{
        backtrack(i+1);
        }
    }
}

int main()
{
    cin >> n >> k;
    a.resize(k+1);
    a[0] = 0;
    backtrack(1);
    return 0;
}