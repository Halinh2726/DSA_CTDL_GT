#include<bits/stdc++.h>
using namespace std;
int n;
int Solve(int* nums)
{
    if(n == 1) return 0;
    int prefixSum[n];
    prefixSum[0] = 0;

    for(int i = 1;i<=n;i++)
     prefixSum[i] = prefixSum[i-1] + nums[i];     
     if(prefixSum[n] - prefixSum[1] == 0) return 0;

    for(int i = 1;i<n;i++)
    {
        int sumLeft = prefixSum[i];
        int sumRight = prefixSum[n] - prefixSum[i+1];
        if(sumLeft == sumRight) return i+1;
    }
    return -1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n+5];
        for(int i = 1;i<=n;i++)
        cin>>a[i];
        cout<<Solve(a)<<'\n';
    }
    return 0;
} 