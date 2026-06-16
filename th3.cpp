#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<vector<int>> tmp(n, vector<int>(n));

int main()
{
    cin >> n >> m;
    for(int i = 1; i<= n; i++)
    {
        for(int j = 2; j<= n; j++)
        {
            cin >> tmp[i][j];
        }
    }

    vector<vector<int>> res;
    vector<int> p;
    for(int i = 1; i<= n; i++)
    {
        p[i] = i;
    }

    do{
        int sum = 0;
        
        for(int i = 1; i<= n; i++)
        {
            sum += a[i][p[i]];
            if(sum > m)
                return;
        }
        if(sum == m)
        {
            res.push_back(p);
        }
    }while(next_permutation(p.begin(), p.end()));

    for(auto x: res)
    {
        for(auto y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
    return 0;
}