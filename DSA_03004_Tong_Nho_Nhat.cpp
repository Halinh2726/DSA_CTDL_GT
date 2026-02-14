#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i< n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        // Tách thành 2 số đồng đều, 2 số đủ nhỏ để cho ra tổng min
        vector<int> so1;
        vector<int> so2;
        for(int i = 0; i< n; i++)
        {
            if(i%2 == 0) 
                so1.push_back(a[i]);
            else
                so2.push_back(a[i]);
        }

        // Chuyển thành 2 số
        long long num1 = 0, num2 = 0;
        for(int i = 0; i< so1.size(); i++)
        {
            num1 = num1*10 + so1[i];
        }
        for(int i = 0; i < so2.size(); i++)
        {
            num2 = num2*10 + so2[i];
        }

        // Tính tổng 2 số
        long long total;
        total = num1 + num2;

        cout << total <<"\n";
    }
    return 0;
}