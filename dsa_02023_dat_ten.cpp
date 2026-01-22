#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<string> a;
vector<string> b;

void backtrack(int pos, int tmp)
{
    if(pos == k)
    {
        for(int i= 0; i< k;i++)
        {
            cout << b[i] << " ";
        }
        cout <<"\n";
        return;
    }

    for(int j = tmp; j< a.size();j++)
    {
        b[pos] = a[j];
        backtrack(pos+1, j+1);
    }
}

int main()
{
    cin >> n >> k;
    a.resize(n);

    for(int i = 0; i< a.size(); i++)
    {
        cin >> a[i];
    }
    b.resize(k);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    backtrack(0,0);
    return 0;
}