#include<bits/stdc++.h>
using namespace std;

/*
Yêu cầu bạn xây dựng một hàng đợi hai đầu với các truy vấn sau đây:

“PUSHFRONT x”: Thêm phần tử x vào đầu của dequeue (0 ≤ x ≤ 1000).

“PRINTFRONT”: In ra phần tử đầu tiên của dequeue. Nếu dequeue rỗng, in ra “NONE”.

“POPFRONT”: Xóa phần tử đầu của dequeue. Nếu dequeue rỗng, không làm gì cả.

“PUSHBACK x”: Thêm phần tử x vào cuối của dequeue (0 ≤ x ≤ 1000).

“PRINTBACK”: In ra phần tử cuối của dequeue. Nếu dequeue rỗng, in ra “NONE”.

“POPBACK”: Xóa phần tử cuối của dequeue. Nếu dequeue rỗng, không làm gì cả.

Dữ liệu vào:

Dòng đầu tiên là số lượng truy vấn Q (Q ≤ 100000).

Mỗi truy vấn có dạng như trên.

Kết quả: 

Với mỗi truy vấn “PRINTFRONT” và “PRINTBACK”, hãy in ra kết quả trên một dòng.
*/

int main()
{
    int n;
    cin >> n;
    deque<int> dq;
    for(int i = 0; i< n; i++)
    {
        string s;
        cin >> s;
        if(s == "PUSHBACK")
        {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if(s == "PUSHFRONT")
        {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if(s == "PRINTFRONT")
        {
            if(dq.empty()) cout << "NONE\n";
            else cout << dq.front() << "\n";
        }
        else if(s == "PRINTBACK")
        {
            if(dq.empty()) cout << "NONE\n";
            else cout << dq.back() << "\n";
        }
        else if(s == "POPFRONT")
        {
            if(!dq.empty()) dq.pop_front();
        }
        else if(s == "POPBACK")
            if(!dq.empty()) dq.pop_back();
    }
    return 0;
}