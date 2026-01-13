#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        for(int i = 0; i< k; i++)
        {
            cin >> a[i];
        }

        int i = k-1;
        while(i>= 0 && a[i] == n-k+i+1)
        {
            i--;
        }
        if(i >= 0)
        {
            a[i]++;
            for(int j = i+1; j<k; j++)
            {
                a[j] = a[j-1]+1;
            }
        }
        else
        {
            for(int i = 0; i< k; i++)
            {
                a[i] = i+1;
            }
        }
        for(auto x: a)
        {
            cout << x << " ";
        }
        cout <<"\n";
    }
    return 0;
}