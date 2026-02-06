#include<bits/stdc++.h>
using namespace std;

int n;
vector<long long> a;

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
        vector<long long> leftmin(n), rightmax(n);
        leftmin[0] = a[0];
        for(int i =1; i< n; i++)
        {
            leftmin[i] = min(a[i], leftmin[i-1]);
        }
        rightmax[n-1] = a[n-1];
        for(int i = n-2; i>= 0; i--)
        {
            rightmax[i] = max(a[i], rightmax[i+1]);
        }
        int i = 0, j= 0;
        long long cnt = -1;
        while(i< n && j < n)
        {
            if(leftmin[i] < rightmax[j])
            {
                cnt = max(cnt, (long long)(j-i));
                j++;
            }
            else i++;
        }
        cout << cnt <<"\n";
    }
    return 0;
}