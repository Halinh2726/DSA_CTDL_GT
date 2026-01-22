#include<bits/stdc++.h>
using namespace std;

int n;
int a[15];
int used[15];

void inkq()
{
    for(int i= 1; i<= n; i++)
    {
        cout << a[i];
    }
    cout <<"\n";
}

void Try(int i)
{

    for(int j = 1; j<= n; j++)
    {
        if(!used[j])
        {
            if(i>1 && abs(a[i-1] - j) == 1) continue;
            a[i] = j;
            used[j] = 1;
            if(i == n)
            {
                inkq();
            }
            else{
                Try(i+1);
            }
            used[j] = 0;
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
        Try(1);
    }
    return 0;
}