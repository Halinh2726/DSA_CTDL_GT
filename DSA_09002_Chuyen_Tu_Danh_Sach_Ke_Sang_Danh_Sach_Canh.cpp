#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    vector<pair<int,int>> edge;

    for(int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int x;

        while(ss >> x)
        {
            if(x > i)  
            {
                edge.push_back({i, x});
            }
        }
    }

    sort(edge.begin(), edge.end());

    for(auto it : edge)
    {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}