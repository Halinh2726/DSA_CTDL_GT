#include<bits/stdc++.h>
using namespace std;

int n, k;
char a[20];
vector<string> tmp;

bool check()
{
    int cnt = 0;
    int cnt_doan_k = 0;

    for(int i = 0; i< n; i++)
    {
        if(a[i] == 'A') cnt++;
        else
        {
            if(cnt == k) cnt_doan_k++;
            if(cnt > k) return false;
            cnt = 0;
        }
    }

    if(cnt == k) cnt_doan_k++;
    if(cnt > k) return false;

    return cnt_doan_k == 1;
}

void backtrack(int pos)
{
    if(pos == n)
    {
        if(check())
        {
            tmp.push_back(string(a,a+n));
        }
        return;
    }

    // Thu tat ca cac kha nang cho vi tri pos
    a[pos] = 'A'; 
    backtrack(pos+1);

    a[pos] = 'B';
    backtrack(pos+1);
}

int main()
{
    cin >> n >> k;
    backtrack(0);

    cout << tmp.size() << "\n";
    for(string s: tmp)
    {
        cout << s <<"\n";
    }
    return 0;
}