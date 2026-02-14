#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;

    string min_a = a, max_a = a;
    string min_b = b, max_b = b;

    for(auto &c: min_a)
        if(c == '6') c = '5';
    for(auto &c: max_a)
        if(c == '5') c = '6';
    for(auto &c: min_b)
        if(c== '6') c = '5';
    for(auto &c : max_b)
        if(c == '5') c = '6';
    
    long long sum_min = stoll(min_a) + stoll(min_b);
    long long sum_max = stoll(max_a) + stoll(max_b);

    cout << sum_min << " " << sum_max;
    return 0;
}