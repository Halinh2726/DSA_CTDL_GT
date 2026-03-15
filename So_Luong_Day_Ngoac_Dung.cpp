#include <bits/stdc++.h>
using namespace std;

int n,k,ans;
string s;
char a[35];



int check()
{
    int tmp = 0; // So ngoac ( chua duoc dong
    int cnt = 0;

    for(int i=1;i<=n;i++)
    {
        if(a[i]=='(')
        {
            tmp++;
            cnt = max(cnt,tmp);
        }
        else
        {
            tmp--;
            if(tmp<0) return 0;
        }
    }

    if(tmp!=0) return 0;

    return cnt==k;
}

void backtrack(int pos)
{
    if(pos>n)
    {
        if(check()) ans++;
        return;
    }

    if(s[pos]=='?')
    {
        a[pos]='(';
        backtrack(pos+1);

        a[pos]=')';
        backtrack(pos+1);
    }
    else
    {
        a[pos]=s[pos];
        backtrack(pos+1);
    }
}

int main()
{
    cin>>k>>s;
    s='0'+s;

    n=s.size()-1;

    backtrack(1);

    cout<<ans;
}