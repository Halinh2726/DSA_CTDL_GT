#include<bits/stdc++.h>
using namespace std;

int n, start;
int a[105][105];

int main(){
    cin >> n;
    cin >> start;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }

    stack<int> st;
    vector<int> euler;

    st.push(start);

    while(!st.empty()){
        int v = st.top();
        bool found = false;

        for(int i=1;i<=n;i++){
            if(a[v][i]){
                st.push(i);
                a[v][i]--;
                a[i][v]--;
                found = true;
                break;
            }
        }

        if(!found){
            euler.push_back(v);
            st.pop();
        }
    }

    reverse(euler.begin(), euler.end());

    for(int x : euler){
        cout << x << "  ";
    }

    return 0;
}