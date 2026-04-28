#include<bits/stdc++.h>
using namespace std;

int goal = 1238040765;
unordered_map<int, int> dist;

int quaytrai(int x)
{
    string a = to_string(x);
    while (a.size() < 10) a = "0" + a;

    string b = a;
    b[0] = a[3];
    b[3] = a[7];
    b[7] = a[8];
    b[8] = a[5];
    b[5] = a[1];
    b[1] = a[0];

    return stoi(b);
}

int quayphai(int x)
{
    string a = to_string(x);
    while (a.size() < 10) a = "0" + a;

    string b = a;
    b[1] = a[4];
    b[4] = a[8];
    b[8] = a[9];
    b[9] = a[6];
    b[6] = a[2];
    b[2] = a[1];

    return stoi(b);
}

void build() {
    queue<int> q;
    q.push(goal);
    dist[goal] = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int step = dist[cur];

        for (int nxt : {quaytrai(cur), quayphai(cur)}) {
            if (!dist.count(nxt)) {
                dist[nxt] = step + 1;
                q.push(nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    build();

    int t; cin >> t;
    while (t--) {
        int x, val = 0;
        for (int i = 0; i < 10; i++) {
            cin >> x;
            val = val * 10 + x;
        }
        cout << dist[val] << "\n";
    }
}