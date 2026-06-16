#include<bits/stdc++.h>
using namespace std;
int n,s,t;
int a[1005][1005];
int d[1005];
bool vis[1005];
int p[1000];


void ktao(){
    cin >> n >> s >> t;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n;i++){
        d[i] = 10000;
        p[i] = 0;
    }
    d[s] = 0;
}


void Try(){
    while(true){
        int maxl = 10000;
        int c = -1;
        for(int i = 1;i <= n;i++){
            if(!vis[i] && d[i] < maxl){
                maxl = d[i];
                c= i;
            }
        }
        if(c == -1 || c == t){
            break;
        }
        vis[c] = true;
        for(int i = 1;i <= n;i++){
            if(!vis[i] && d[i] > d[c] + a[c][i]){
                d[i] = d[c] + a[c][i];
                p[i] = c;
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
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();

    }

}


int main(){
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    ktao();
    Try();

}