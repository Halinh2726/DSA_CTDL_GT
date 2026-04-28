#include<bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b)
{
    return a.size() != b.size() ? a.size() < b.size() : a < b;
}

int main()
{
    vector<string> res;

    for(int i = 2;res.size() < 10000; i +=2)
    {
        int half = i/2;

        int total = (1 << half);
        for(int mask = 0; mask < total; mask++)
        {
            string left = "";
            for(int i = half -1; i>= 0; i--)
            {
                left += ((mask >> i) & 1) ? '8' : '6';
            }
            string right = left;
            reverse(right.begin(), right.end());
            res.push_back(left + right);
        }
    }
    sort(res.begin(), res.end(), cmp);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 0; i< n;i++)
        {
            if(i > 0) cout << ' ';
            cout << res[i];
        }
        cout << "\n";
    }
    return 0;
}