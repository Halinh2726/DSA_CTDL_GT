#include <bits/stdc++.h>
using namespace std;

int n, a[100];
void in() {
    for (int i=1; i<=n; i++) {
        if (a[i]==a[i-1]) cout << 0;
        else if (a[i]==0) cout << 1;
        else cout << a[i];
    } cout << " ";
}

void Try(int i) {
    for (int j=0; j<=1; j++){
        a[i]=j;
        if (i==n) in();
        else Try(i+1);
    }
}
int main () {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        memset(a, 0, sizeof(a));
        Try(1);
        cout << "\n";
    }
    return 0;
}