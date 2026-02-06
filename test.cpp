#include<bits/stdc++.h>
using namespace std;

int n;
int a[100];
int used[100];
void inkq()
{
    for(int i = 1;i<= n; i++)
    {
        cout << a[i];
    }
    cout <<" ";
}
void backtrack(int pos)
{
    for(int i = 1; i<= n; i++)
    {
        if(!used[i])
        {
            a[pos] = i;
            used[i] = 1;
            if(pos == n)
            {
                inkq();
            }
            else{
                backtrack(pos+1);
            }
            used[i] = 0;
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
        backtrack(1);
        cout <<"\n";
    }
    return 0;
}