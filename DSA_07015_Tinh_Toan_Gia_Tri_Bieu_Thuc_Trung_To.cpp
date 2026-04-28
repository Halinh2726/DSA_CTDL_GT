#include<bits/stdc++.h>
using namespace std;

/*
stack<int>: lưu toán hạng
stack<char>: lưu toán tử
 Xét từ trái sang phải: nếu gặp số thì đẩy vào stack số, 
 (: đưa vào stack toán tử
): Tính giá trị cho đến khi gặp )
Các toán tử cộng trừ nhân chia
    Nếu toán tử trên đỉnh stack có độ ưu tiên ≥ hiện tại → tính trước
    Sau đó push toán tử hiện tại vào
*/
int priority(char x)
{
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    return 0;
}

long long tinh(long long a, long long b, char x)
{
    if(x == '+') return a+b;
    if(x == '-') return a-b;
    if(x == '*') return a*b;
    if(x == '/') return a/b;
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        stack<char> toan_tu;
        stack<long long> toan_hang;

        for(int i = 0; i < s.size(); i++)
        {
            if(isdigit(s[i]))
            {
                long long tmp = 0;
                while(i < s.size() && isdigit(s[i]))
                {
                    tmp = tmp * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                toan_hang.push(tmp);
            }
            else if(s[i] == '(')
            {
                toan_tu.push(s[i]);
            }
            else if(s[i] == ')')
            {
                while(toan_tu.top() != '(')
                {
                    long long b = toan_hang.top(); toan_hang.pop();
                    long long a = toan_hang.top(); toan_hang.pop();
                    char c = toan_tu.top(); toan_tu.pop();
                    toan_hang.push(tinh(a, b, c));
                }
                toan_tu.pop(); // bỏ '('
            }
            else
            {
                while(!toan_tu.empty() && priority(toan_tu.top()) >= priority(s[i]))
                {
                    long long b = toan_hang.top(); toan_hang.pop();
                    long long a = toan_hang.top(); toan_hang.pop();
                    char c = toan_tu.top(); toan_tu.pop();
                    toan_hang.push(tinh(a, b, c));
                }
                toan_tu.push(s[i]);
            }
        }

        while(!toan_tu.empty())
        {
            long long b = toan_hang.top(); toan_hang.pop();
            long long a = toan_hang.top(); toan_hang.pop();
            char c = toan_tu.top(); toan_tu.pop();
            toan_hang.push(tinh(a, b, c));
        }

        cout << toan_hang.top() << "\n";
    }
}