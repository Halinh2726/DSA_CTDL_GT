#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<vector<int>> res;
vector<int> tmp;
int sum = 0;

void Try(vector<int> &a, int ind)
{
    if(sum > k)
        return;
    if(sum == k)
    {
        res.push_back(tmp);
        return;
    }
    if(ind == n)
        return;
    
    sum+= a[ind];
    tmp.push_back(a[ind]);
    Try(a,ind+1);

    sum-= a[ind];
    tmp.pop_back();
    Try(a,ind+1);
}

int main()
{
    cin >> n >> k;
    vector<int> a(n);
    for(int i= 0; i< n; i++)
    {
        cin >> a[i];
    }
    Try(a, 0);

    reverse(res.begin(), res.end());
    int cnt = 0;
    for(auto &x: res)
    {
        for(auto i : x)
            cout << i << " ";
        cout << "\n";
        cnt++;
    }  
    cout << cnt << "\n";
    return 0;
}