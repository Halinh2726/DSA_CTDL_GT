#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<vector<int>> tmp;

void inkq()
{
    
    for(int i = tmp.size()-1; i>= 0; i--)
    {
        cout << "Buoc " << i << ": ";
        for(auto x: tmp[i])
        {
            cout << x << " ";
        }
        cout <<"\n";
    }
}

void insertionsort(vector<int> a, int n)
{
    tmp.push_back({a[0]});
    for(int i= 1; i< n; i++)
    {
        int x = a[i], pos = i-1;
        while(pos >= 0 && x < a[pos])
        {
            a[pos +1] = a[pos];
            pos--;
        }
        a[pos+1] = x;
        
        vector<int> cnt;
        for(int j = 0; j<= i; j++)
        {
            cnt.push_back(a[j]);
        }
        tmp.push_back(cnt);
    }
    inkq();
}

int main()
{
    cin >> n; 
    a.resize(n);
    for(int i= 0; i< n; i++)
    {
        cin >> a[i];
    }
    insertionsort(a,n);
    return 0;
}