#include<bits/stdc++.h>
using namespace std;

int n;
// int snt(int n)
// {
//     if(n < 2) return 0;
//     for(int i = 2;i*i <= n;i++)
//     {
//         if(n%i == 0)  return 0; 
//     }
//     return 1;
// }

// bool ktr(int n)

// {
//     while(n>0)
//     {
//         if(snt(n) == false)
//         {
//             return false;
//         }
//         n = n/10;
//     }
//     return true;
// }

bool isPrime[10000001];

bool check(int n)
{
    while(n)
    {
        if(!isPrime[n]) return false;
        n /= 10;
    }
    return true;
}
void sieve(int n)
{
    for(int i = 0; i<= n; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2; i*i <= n; i++)
    {
        if(isPrime[i] == true)
        {
            for(int j = i*i; j<= n; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
}
int main()
{
    int l,r;
    cin >> l >> r;
    int cnt = 0;
    
    sieve(r);
    for(int i = l; i<= r; i++)
    {
        if(check(i))
        {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}