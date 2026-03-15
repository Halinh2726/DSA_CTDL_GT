#include<bits/stdc++.h>
using namespace std;

/*
Chọn công việc kết thúc sớm nhất
Sắp xếp công việc kết thúc sớm nhất--> muộn nhất để tối ưu việc chọn công việc
Sau đó so sánh tgian bắt đầu của cvc sau với thời gian kết thúc của công việc trước
Nếu tgian bđầu nhỏ hơn thì ko chọn, còn lớn hơn thì chọn
*/
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int,int> b)
{
    return a.second < b.second;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int,int>> jobs(n);

        for(int i = 0; i < n; i++) {
            cin >> jobs[i].first >> jobs[i].second;
        }
        
        sort(jobs.begin(), jobs.end(), cmp);
        int count = 0;
        int last_end = -1;

        for(int i = 0; i < n; i++) {
            if(jobs[i].first >= last_end) {
                count++;
                last_end = jobs[i].second;
            }
        }

        cout << count << "\n";
    }

    return 0;
}