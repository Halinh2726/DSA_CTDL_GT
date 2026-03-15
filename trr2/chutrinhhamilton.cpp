#include<bits/stdc++.h>
using namespace std;


int N;              
int v0;            
int adj[100][100];  
int X[100];         
bool chuaxet[100]; 


void GhiNhan() {
    for (int i = 1; i <= N; i++) {
        cout << X[i] << " ";
    }
    cout << v0 << endl; 
}


void Hmt(int k) {
    
    int u = X[k - 1];
    
    
    for (int y = 1; y <= N; y++) {
      
        if (adj[u][y] == 1 && chuaxet[y]) {
            X[k] = y;           
            chuaxet[y] = false; 

          
            if (k == N) {
               
                if (adj[y][v0] == 1) {
                    GhiNhan();
                }
            } else {
                Hmt(k + 1); 
            }

            
            chuaxet[y] = true;
        }
    }
}

int main() {
    if (!(cin >> N >> v0)) return 0;

   
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> adj[i][j];
        }
    }

    
    for (int i = 1; i <= N; i++) chuaxet[i] = true;

    X[1] = v0;           
    chuaxet[v0] = false; 

    
    Hmt(2);

    return 0;
}