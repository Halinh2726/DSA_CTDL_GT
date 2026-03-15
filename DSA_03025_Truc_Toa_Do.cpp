#include<bits/stdc++.h>
using namespace std;

/*
Sắp xếp các cặp tọa độ theo thứ tự tăng dần của phần tử thứ 2 trong cặp.
Giống như bài trc, thì so sánh phần tử thứ 1 của tọa độ sau với phần tử thứ 2 của tọa độ trc
nếu thỏa mãn thì sẽ cnt++; 
*/
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<pair<int, int>> dt(n);
        for(int i = 0; i< n; i++)
        {
            cin >> dt[i].first >> dt[i].second;
        }

        sort(dt.begin(), dt.end(), cmp);
        int cnt = 0;
        int last = -1;

        for(int i = 0; i< n; i++)
        {
            if(dt[i].first >= last)
            {
                cnt++;
                last = dt[i].second;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}