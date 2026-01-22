#include<bits/stdc++.h>
using namespace std;

int n;
char a[10];
int used[10];

bool check(char x)
{
    return x == 'A' || x == 'E';
}
void inkq()
{

    for(int i = 2;i<=n-1;i++)
    {
        if(!check(a[i-1]) && !check(a[i+1]) && check(a[i]))
        {
            return;
        }
    }

    for(int i= 1;i <= n; i++)
    {
        cout << a[i];
    }
    cout << "\n";
}

void Try(int i)
{
    for(int j = 0; j< n;j++)
    {
        if(!used[j])
        {
            a[i] = char('A' + j);
            used[j] = 1;
        
            if(i == n)
            {
                inkq();
            }
            else
            {
                Try(i+1);
            }
            used[j] = 0;
        }
    }
}

int main()
{
    char c;
    cin >> c;
    n = c - 'A' + 1;
    Try(1);
    return 0;   
}
