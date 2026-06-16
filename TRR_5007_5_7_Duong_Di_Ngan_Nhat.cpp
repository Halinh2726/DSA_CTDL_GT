#include<bits/stdc++.h>
using namespace std;

int n,s,t;
int a[1005][1005];
int d[10005];
int p[1005];

void ktao(){
    cin >> n >> s >> t;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        d[i] =10000;
        p[i] = 0;
    }
    d[s] = 0;
}

void Try() {
    int m = n - 1;
    while(m--){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(d[j] > d[i] + a[i][j]){
                    d[j] = d[i] + a[i][j];
                    p[j] = i;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[j] > d[i] + a[i][j]) {
                cout << -1 << endl;
                return;
            }
        }
    }

    if(p[t] == 0){
        cout << 0 << endl;
        return;
    }
    stack<int> st;
    cout << d[t] << endl;
    while(t != 0){
        st.push(t);
        t = p[t];

    }
    while ((!st.empty()))
    {
        /* code */cout << st.top() << " ";
        st.pop();
    }
    
}

int main(){
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);
    ktao();
    Try();

}