#include<bits/stdc++.h>
using namespace std;

vector<string> res;
int n;
int a[20][20];

void backtrack(int i, int j, string s)
{
    if(i >= n || j>= n)
    {
        return;
    }
    
    if(i == n-1 && j == n-1)
    {
        res.push_back(s);
        return;
    }

    backtrack(i,j+1, s + 'D');
    backtrack(i+1,j, s+'R');
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i= 0; i< n; i++)
        {
            for(int j = 0; j< n; j++)
            {
                cin >> a[i][j];
            }
        }

        res.clear();
        if(a[0][0] == 1)
        {
            backtrack(0,0,"");
        }

        if(res.empty())
        {
            cout << "-1\n";
        }
        else{
            sort(res.begin(), res.end());
            for(auto &x:res)
            {
                cout << x << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}