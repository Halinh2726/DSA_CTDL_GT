#include<bits/stdc++.h>
using namespace std;


int quaytrai(int a[])
{
    int b[7];
    b[1] = a[4];
    b[3] = a[3];
    b[6] = a[6];
    b[2] = a[1];
    b[4] = a[5];
    b[5] = a[2];

    int out = 0;
    for (int i = 1; i <= 6; i++)
    {
        out = out * 10 + b[i];
    }
    return out;
}

int quayphai(int a[])
{
    int b[7];
    b[1] = a[1];
    b[2] = a[5];
    b[3] = a[2];
    b[4] = a[4];
    b[5] = a[6];
    b[6] = a[3];

    int out = 0;
    for (int i = 1; i <= 6; i++)
    {
        out = out * 10 + b[i];
    }
    return out;
}

int bfs(int start, int target)
{
    queue<pair<int, int>> q;
    set<int> visited;
    q.push({start,0});
    visited.insert(start);
    while(!q.empty())
    {
        int current = q.front().first;
        int step = q.front().second;
        q.pop();
        if(current == target)
            return step;
        int a[7];
        int tmp = current;
        for(int i = 6; i>= 1; i--)
        {
            a[i] = tmp%10;
            tmp/=10;
        }
        int left = quaytrai(a);
        int right = quayphai(a);
        if(visited.find(left) == visited.end())
        {
            visited.insert(left);
            q.push({left, step + 1});
        }
        if(visited.find(right) == visited.end())
        {
            visited.insert(right);
            q.push({right, step + 1});
        }
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int start = 0, target = 0;

        for(int i = 1; i <= 6; i++)
        {
            int x; cin >> x;
            start = start * 10 + x;
        }

        for(int i = 1; i <= 6; i++)
        {
            int x; cin >> x;
            target = target * 10 + x;
        }

        cout << bfs(start, target) << "\n";
    }
}