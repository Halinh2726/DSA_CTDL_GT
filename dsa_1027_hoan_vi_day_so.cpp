#include<bits/stdc++.h>
using namespace std;

int n;
int ok = 1;
vector<int> a;

void sinh_ke_tiep()
{
    int i = n-2;
    while(i>= 0 && a[i] >= a[i+1]) i--;
    if(i< 0)
    {
        ok =0;
        return;
    }
    else{
        int j = n-1;
        while(a[i] >= a[j]) j--;
        swap(a[i], a[j]);
        reverse(a.begin() + i+1, a.end());
    }
}
int main()
{
    cin >> n;
    a.resize(n);
    for(int i= 0; i< n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ok = 1;
    while(ok)
    {
        for(int i = 0; i< n; i++)
        {
            cout << a[i] << " ";
        }
        cout <<"\n";
        sinh_ke_tiep();
    }
    return 0;
}