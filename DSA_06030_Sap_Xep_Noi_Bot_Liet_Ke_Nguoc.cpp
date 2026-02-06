#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<vector<int>> tmp;

void inkq()
{
    for(int i = tmp.size() -1; i >= 0; i--)
    {
        cout << "Buoc " << i+1 <<": ";
        for(int x: tmp[i])
        {
            cout << x << " ";
        }
        cout <<"\n";
    }
}

void bubblesort(vector<int> a, int n)
{
    tmp.clear();
    for(int i = 0; i< n-1; i++)
    {
        int check = 0;
        for(int j = 0; j< n - i- 1; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                check = 1;
            } 
        }
        if(check)
            tmp.push_back(a);
        else
            break;
    }
    inkq();
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        a.resize(n);
        for(int i = 0; i< n; i++)
        {
            cin >> a[i];
        }
        bubblesort(a,n);
    }
    return 0;
}