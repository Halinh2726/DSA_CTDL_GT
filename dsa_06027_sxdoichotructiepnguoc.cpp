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
        for(int i = 0; i<n;i++)
        {
            cin >> a[i];
        }

        vector<vector<int>> tmp;

        for(int i = 0; i<n-1; i++)
        {
            for(int j = i+1; j<n ;j++)
            {
                if(a[i] > a[j])
                {
                    swap(a[i], a[j]);
                }
            }
            tmp.push_back(a);
        }

        for(int i= tmp.size()-1; i>= 0; i--)
        {
            cout << "Buoc " << i+1 << ": ";
            for(int x : tmp[i])
            {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}