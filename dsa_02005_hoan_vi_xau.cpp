#include<bits/stdc++.h>
using namespace std;

string s;
int n;
int used[20];
char res[20];

void backtrack(int k)
{
    if(k==n)
    {
        for(int i= 0; i< n; i++)
        {
          cout << res[i];  
        }
        cout << " ";
        return;
    }

    for(int i = 0; i< n; i++)
    {
        if(!used[i])
        {
            used[i] = 1;
            res[k] = s[i];
            backtrack(k+1);
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
        cin >> s;
        n = s.size();

        sort(s.begin(), s.end());
        memset(used, 0, sizeof(used));
        backtrack(0);
        cout << "\n";
    }
    return 0;
}