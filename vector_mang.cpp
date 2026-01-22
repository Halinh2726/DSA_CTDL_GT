#include <bits/stdc++.h>
using namespace std;

int n, target;
int sum;
bool found;
vector<int> a;

// Khi tìm được lời giải
void inkq() {
    found = true;
}

// Quay lui
void Try(int i) {
    if (found) return;        // đã có đáp án thì dừng
    if (sum == target) {     // tìm được tổng = S/2
        inkq();
        return;
    }
    if (i == n || sum > target) return;

    // 1. CHỌN a[i]
    sum += a[i];
    Try(i + 1);
    sum -= a[i];   // quay lui

    // 2. KHÔNG CHỌN a[i]
    Try(i + 1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        a.resize(n);

        int S = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            S += a[i];
        }

        if (S % 2 != 0) {
            cout << "NO\n";
            continue;
        }

        target = S / 2;
        sum = 0;
        found = false;

        Try(0);

        cout << (found ? "YES\n" : "NO\n");
    }
}
