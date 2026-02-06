// sinh nhi phan
// Try(i):
//     for v in {0, 1}:
//         a[i] = v
//         if i == n:
//             output a
//         else:
//             Try(i + 1)
 


// Sinh to hop
// Try(i):
//     for v = a[i-1] + 1 → n - k + i:
//         a[i] = v
//         if i == k:
//             output a
//         else:
//             Try(i + 1)



// Sinh hoan vi
// Try(i):
//     for v = 1 → n:
//         if not used[v]:
//             a[i] = v
//             used[v] = true
//             if i == n:
//                 output a
//             else:
//                 Try(i + 1)
//             used[v] = false

// Sang so nguyen to

bool isPrime[10000001];
void seive(int n)
{
    for(int i = 2; i<= n; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i*i <= n; i++)
    {
        if(isPrime[i])
        {
            for(int j = i*2; j<= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}
