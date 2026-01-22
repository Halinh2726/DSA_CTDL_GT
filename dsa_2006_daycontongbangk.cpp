#include<bits/stdc++.h>
using namespace std;

int n, k;
int sum;
vector<vector<int>> tmp;
vector<int> res;

void Try(vector<int> &a, int i)
{

    if(sum > k)
    {
        return;
    }

    if(sum == k)
    {
        tmp.push_back(res);
        return;
    }

    if(i == n)
    {
        return;
    }

    sum += a[i];
    res.push_back(a[i]);
    Try(a, i + 1);

    sum -= a[i];
    res.pop_back();
    Try(a,i+1);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {

        cin >> n >> k;
        vector<int> a(n);
        for(int i=0 ; i< n; i++)
        {
            cin >> a[i];
        }

        sum = 0;
        res.clear();
        tmp.clear();
        sort(a.begin(), a.end());
        Try(a,0);
        
        if(tmp.empty())
        {
            cout << "-1\n";
        }
        else{
        for(auto &x : tmp)
            {
                cout << "[";
                for(int i = 0; i < x.size(); i++)
                {
                    cout << x[i];
                    if(i != x.size() - 1) cout << " ";
                }
                cout << "] ";
            }
            cout << "\n";
        }
    }
    return 0;
}