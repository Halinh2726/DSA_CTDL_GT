#include<bits/stdc++.h>
using namespace std;


int n;
int a[1005][1005];
int v[1005][1005];


void ktao(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
            if(a[i][j] > 0 && a[i][j] <= 50){
                v[i][j] = j;
            }
        }
    }
}

void Try(){
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(a[i][j] > a[i][k] + a[k][j]){
                    a[i][j] = a[i][k] + a[k][j];
                    v[i][j] = v[i][k];
                }
            }
        }
    }
    int u = -1;
    int h = -1;
    int maxl = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] > maxl && a[i][j] != 0 && a[i][j] != 10000) {
                maxl = a[i][j];
                u = i;
                h = j;

            }
        }
    }
    if(u == -1){
        cout << 0 << endl;
        return;
    }
    cout << u << " " << h << " " << maxl <<endl;

    int m = v[u][h];
    cout << u <<  " ";
    while(m != h){
        cout << m <<  " ";
        m = v[m][h];

    }
    cout << h << endl;

}


int main(){
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    ktao();
    Try();
}