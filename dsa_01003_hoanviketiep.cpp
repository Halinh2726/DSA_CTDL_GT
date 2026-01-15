#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0 ; i< n; i++)
        {
            cin >> a[i];
        }

        int i = n-2; // 5 4 3 2 1
        while(i>= 0 && a[i] > a[i+1])
            i--;
        if(i >= 0)
        {
            int j = n-1;
            while(a[i] >= a[j]) j--;
            swap(a[i], a[j]);
            reverse(a.begin()+i+1, a.end());
            // cout << "YES" << endl;
        } 
        else
        {
            for(int i= 0; i< n;i++)
            {
                a[i] = i+1;
            }
            // cout << "NO" << endl;
        }
        for(auto x: a)
        {
            cout << x <<" ";
        }
        cout <<"\n";
    }
    return 0;
}