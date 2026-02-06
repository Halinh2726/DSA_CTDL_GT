#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int cnt = 1;
vector<vector<int>> tmp;

void inkq()
{
    for(int i = tmp.size() - 1; i>= 0; i--)
    {
        cout << "Buoc " << i+1 << ": ";
        for(auto x : tmp[i])
        {
            cout << x <<" ";
        }
        cout <<"\n";
    }
}

void selectionsort(vector<int> a, int n)
{
    for(int i= 0; i< n-1; i++)
    {
        int min_pos = i;
        for(int j = i+1; j<n; j++)
        {
            if(a[j] < a[min_pos])
                min_pos = j;
        }
        swap(a[i], a[min_pos]);
        tmp.push_back(a);
   }
   inkq();
}
int main()
{
    cin >> n;
    a.resize(n);
    for(int i = 0; i< n; i++)
    {
        cin >> a[i];
    }
    selectionsort(a,n);
    return 0;
}