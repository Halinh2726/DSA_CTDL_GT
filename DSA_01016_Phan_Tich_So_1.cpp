#include<bits/stdc++.h>
using namespace std;
/*
sum : số phần tử còn thiếu khi tính tổng n
last: Số lớn nhất được phép chọn tiếp theo. Dùng để giữ dãy không tăng và tránh trùng lặp
vector<int> a: dùng để lưu các cặp phần tử tổng bằng n
*/
int n;
vector<int> a;
void  backtrack(int sum, int last)
{
    if(sum == 0)
    {
        cout << "(";
        for(int i = 0; i< a.size(); i++)
        {
            cout << a[i];
            if(i != a.size() - 1) 
                cout << " ";
        }
        cout << ")" << " ";
        return;
    }
    

    else
    {
        for(int i = min(sum, last); i>=1; i--) // Thử tất cả các khả năng
        {
            a.push_back(i);
            backtrack(sum - i, i);
            a.pop_back();// Quay lui thử nhánh khác
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        backtrack(n,n);
        cout << "\n";
    }
    return 0;
}