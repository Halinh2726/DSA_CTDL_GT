#include<bits/stdc++.h>
using namespace std;

/*
1.Trả về kích thước của queue
2.Kiểm tra xem queue có rỗng không, nếu có in ra “YES”, nếu không in ra “NO”.
3. Cho một số nguyên và đẩy số nguyên này vào cuối queue.
4. Loại bỏ phần tử ở đầu queue nếu queue không rỗng, nếu rỗng không cần thực hiện.
5. Trả về phần tử ở đầu queue, nếu queue rỗng in ra -1.
6. Trả về phần tử ở cuối queue, nếu queue rỗng in ra -1.
*/
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        queue<int> q;
        for(int i = 0; i< n; i++)
        {
            int x; cin >> x;
            if(x == 3)
            {
                int y;
                cin >> y;
                q.push(y);
            }
            else if(x == 1)
                cout << q.size() << "\n";
            else if(x == 2)
            {
                if(q.empty())
                    cout << "YES\n";
                else cout << "NO\n";
            }
            else if(x == 4)
            {
                if(!q.empty())
                    q.pop();
                else
                    continue;
            }
            else if(x == 5)
            {
                if(q.empty()) cout << "-1\n";
                else 
                    cout << q.front() << "\n";
            }
            else if (x == 6)
            {
                if(q.empty())
                    cout << "-1\n";
                else
                    cout << q.back()<< "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}