#include<bits/stdc++.h>
using namespace std;
// 1. set
// 2.priority queue



// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         priority_queue<long long , vector<long long>, greater<long long>> pq;
//         int n;
//         cin >> n;
//         vector<long long> a(n);
//         for(int i= 0; i< n; i++)
//         {
//             cin >> a[i];
//             pq.push(a[i]);
//         }
        
//         long long opt = 0;
//         while(pq.size() > 1)
//         {
//             long long first = pq.top();
//             pq.pop();
//             long long second = pq.top();
//             pq.pop();
//             opt = opt + first + second;
//             pq.push(first + second);
//         }
//         cout << opt <<"\n";
//     }
// }

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        multiset<long long> ms;
        for(int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            ms.insert(x);
        }

        long long res = 0;

        while(ms.size() > 1) {
            //lấy 2 phần tử nhỏ nhất
            auto it1 = ms.begin();
            long long a = *it1;
            ms.erase(it1);

            auto it2 = ms.begin();
            long long b = *it2;
            ms.erase(it2);

            long long sum = a + b;
            res += sum;

            ms.insert(sum);
        }

        cout << res << endl;
    }
    return 0;
}