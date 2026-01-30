#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[21];

void backtrack(int pos)
{
    if(pos > k)
    {
        for(int i=1;i<= k;i++)
        {
            cout << a[i] <<" ";
        }
        cout <<"\n";
        return;
    }

    for(int i = a[pos-1]+1; i<= n+pos-k; i++)
    {
        a[pos] = i;
        backtrack(pos+1);
    }
}

int main()
{
    cin >> n >> k;
    backtrack(1);
    return 0;
}