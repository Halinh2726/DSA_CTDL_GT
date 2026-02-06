#include<bits/stdc++.h>
using namespace std;

int n;
int tmp[20], cuoi[20];
int used = 1;
bool check(int a[], int b[], int n)
{
    int khac1 = 0;
    for(int i= 0; i< n; i++)
    {
        if(a[i] != b[i]) khac1++;
    }
    return khac1 == 1;
}

void backtrack(int pos)
{
    if(pos == n)
    {
        if(used)
        {
            for(int i= 0; i<n; i++)
            {
                if(tmp[i] != 0) return;
            }
            for(int i =0; i<n;i++)
            {
                cout << tmp[i];
                cuoi[i] = tmp[i];
            }
            cout << " ";
            used = 0;
        }
    else
    {
        if(check(tmp,cuoi, n))
        {
            for(int i = 0; i< n; i++)
            {
                cout << tmp[i];
                cuoi[i] = tmp[i];
            }
            cout << " ";
        }
    }
    return;
    }

    tmp[pos] = 0;
    backtrack(pos+1);
    tmp[pos] = 1;

    backtrack(pos+1);
}

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        cin >> n;
        used = 1;
        memset(cuoi, 0, sizeof(cuoi));
        backtrack(0);
        cout <<"\n";
    }
    return 0;
}