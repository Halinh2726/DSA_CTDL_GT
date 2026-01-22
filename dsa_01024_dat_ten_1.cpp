#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<string> a;
vector<string> b;
void inkq()
{
    for(int i =0; i< k; i++)
    {
        cout << b[i] << " "; 
    }
    cout << "\n";
}

void backtrack(int i, int x)
{
    if(i == k)
        {
            inkq();
            return;
        }
    for(int j = x; j< a.size(); j++)
    {
        b[i] = a[j];
        backtrack(i+1, j+1);
    } 
}

int main()
{
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i< n; i++)
    {
        cin >> a[i];
    }
    b.resize(k);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    backtrack(0,0);
    return 0;
}