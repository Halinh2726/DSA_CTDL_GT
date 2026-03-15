#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
vector<pair<int,int>> edge;
int a[1001][1001];

int main()
{
    cin >> n;
    cin.ignore();
    for(int i= 1; i<= n; i++)
    {
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while(ss >> num)
        {
            if(stoi(num) > i)
            {
                edge.push_back({i, stoi(num)});
            }
        }
    }

    for(auto it: edge)
    {
        cout << it.first << " " << it.second;
        cout <<"\n";
    }
    return 0;
}