#include <bits/stdc++.h>
using namespace std;

const int MOD = 100;

int norm(long long x) {
    return (x % MOD + MOD) % MOD;
}

struct Num {
    int a, b; // a + b√3
};

Num nhanso(Num x, Num y) {
    return {
        norm(x.a * y.a + 3LL * x.b * y.b),
        norm(x.a * y.b + x.b * y.a)
    };
}

Num power(long long n) {
    Num res = {1, 0};  // 1
    Num tmp = {2, 1};  // 2 + √3

    while (n) {
        if (n & 1) res = nhanso(res, tmp);
        tmp = nhanso(tmp, tmp);
        n >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long n;
        cin >> n;

        if (n == 0) {
            cout << "01\n";
            continue;
        }

        Num ans = power(n);
        cout << setw(2) << setfill('0') << ans.a << '\n';
    }
    return 0;
}
