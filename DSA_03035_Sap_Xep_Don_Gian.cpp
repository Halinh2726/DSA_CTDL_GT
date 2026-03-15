#include<bits/stdc++.h>
using namespace std;

/*
Bản chất: Là đi tìm dãy con tăng dài nhất
Muốn tìm dãy con tăng dài nhất phải lưu chỉ số vào 1 mảng, dãy con tăng dài nhất chính là mảng lưu chỉ số
tăng dài nhất 
*/
int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> index(n+1);
    for(int i= 1; i<= n; i++)
    {
        cin >> a[i];
        index[a[i]] = i;
    }

    int cnt = 1;
    int max_n = 1;
    for(int i = 1; i< n; i++)
    {
        if(index[i] < index[i+1])
            cnt++;
        else
            cnt = 1;
        
        max_n = max(cnt, max_n);
    }   
    cout << n - max_n << "\n";
    return 0;
}