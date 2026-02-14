#include<bits/stdc++.h>
using namespace std;

void greedy(long long values, vector<long long> &coins, vector<long long> &ans, int n)
{
    for(int i = n-1; i>= 0; i--)
    {
        ans[i] = 0;
        while(coins[i] <= values)
        {
            values -= coins[i];
            ans[i]++;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector<long long> coins = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
        vector<long long> ans(10);
        greedy(n,coins, ans, 10);
        long long count = 0;
        for(int i = 0; i< 10; i++)
        {
            count += ans[i];
        }
        cout << count <<"\n";
    }
    return 0;
}