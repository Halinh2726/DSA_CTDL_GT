#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10000000;
bool isPrime[MAXN + 1];

void sieve() {
    fill(isPrime, isPrime + MAXN + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

// int snt(int n)
// {
//     if(n< 2) return 0;
//     for(int i = 2; i*i <= n;i++)
//     {
//         if(n%i ==0) return 0;
//     }
//     return 1;
// }

int main()
{
    sieve();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int ok = 0;
        for(int i =2; i<=n/2;i++)
        {
            if(isPrime[i] && isPrime[n-i])
            {
                cout << i << " " << n-i <<"\n";
                ok = 1;
                break;
            }
        }
        if(!ok) cout <<"-1\n";
    }
    return 0;
}