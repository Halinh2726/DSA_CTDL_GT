#include<bits/stdc++.h>
using namespace std;
// 1. set
// 2.priority queue



int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        priority_queue<long long , vector<long long>, greater<long long>> pq;
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i= 0; i< n; i++)
        {
            cin >> a[i];
            pq.push(a[i]);
        }
        
        long long opt = 0;
        while(pq.size() > 1)
        {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            opt = opt + first + second;
            pq.push(first + second);
        }
        cout << opt <<"\n";
    }
}