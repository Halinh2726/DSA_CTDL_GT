#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b;
    cin >> a >> b;

    vector<long long> somayman;
    queue<long long> q;
    q.push(4);
    q.push(7);

    while(!q.empty())
    {
        long long x= q.front();
        q.pop();

        if(x > 1e10) continue;
        somayman.push_back(x);
        q.push(x * 10 +4);
        q.push(x*10 + 7);
    }

    sort(somayman.begin(), somayman.end());

    long long ans = 0;
    long long tmp = a;

    for(long long x : somayman)
    {
        if(x < tmp) continue;
        long long r = min(b,x);
        ans += (r - tmp +1) * x;

        tmp = x+1;
        if(tmp > b) break;
    }
    cout << ans <<"\n";
    return 0;
}