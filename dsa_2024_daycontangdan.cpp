#include<bits/stdc++.h>
using namespace std;

int n;
int a[30];
vector<int> tmp;
vector<string> res;

void backtrack(int i)
{
    if(i==n)
    {
        if(tmp.size() >= 2)
        {
            string s = "";
            for(int x: tmp) s+= to_string(x) + " ";
            s.pop_back();
            res.push_back(s);
        }
        return;
    }

    // Chon
    backtrack(i+1);

    // Khong chon
    if(tmp.empty() || a[i] > tmp.back())
    {
        tmp.push_back(a[i]);
        backtrack(i+1);
        tmp.pop_back();
    }
}

int main()
{
    cin >> n;
    for(int i =0 ; i< n; i++)
    {
        cin >> a[i];
    }

    backtrack(0);
    sort(res.begin(), res.end());
    for(auto &s:res)
    {
        cout << s << "\n";
    }
    return 0;
}