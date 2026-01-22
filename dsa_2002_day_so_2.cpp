#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);

        for(int i = 0; i< n; i++)
        {
            cin >> a[i];
        }

        vector<vector<int>> tmp;

        while(true)
        {
            tmp.push_back(a);
            if(a.size() == 1) break;

            vector<int> b;
            for(int i= 0; i< a.size() - 1; i++)
            {
                b.push_back(a[i] + a[i+1]);
            }
            a=b;
        }

        for(int i = tmp.size()-1; i>= 0 ; i--)
        {
            cout << "[";
            for(int j = 0; j< tmp[i].size(); j++)
            {
                cout << tmp[i][j];
                 if(j+1 < tmp[i].size()) cout << " ";
            }
            cout << "]";
            if(i != 0) cout << " ";
        }
        if(t) cout <<"\n";
    }
    return 0;
}