#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<long long> a;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        priority_queue<pair<long long,int>> pq;
        cin >> n >> k;
        a.resize(n);
        for(int i = 0; i< n; i++)
        {
            cin >> a[i];
            pq.push({a[i], i});
            // Loại bỏ các phần tử ngoài cửa sổ
            while(!pq.empty() && pq.top().second <= i - k)
            {
                pq.pop();
            }
            // In ra ket quả
            if( i >= k-1)
            {
                cout << pq.top().first << " ";
            }
        }
        cout <<"\n";
    }
    return 0;
}

