#include<bits/stdc++.h>
using namespace std;

int n;
int a[5][5];
bool visited[5][5];
vector<string> tmp;

int dx[] = {1,0,0,-1}; // mã hóa hướng di chuyển trong ma trận
// → giúp duyệt lân cận bằng vòng lặp thay vì viết tay từng hướng
int dy[] = {0,-1,1,0};
char movechar[] = {'D', 'L', 'R', 'U'};

void dfs(int i, int j, string path)
{
    if(i == n-1 && j == n-1)
    {    tmp.push_back(path);
        return;
    }

    for(int k = 0; k< 4; k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if(ni >= 0 && nj >= 0 && ni <n && nj < n && a[ni][nj] == 1 && !visited[ni][nj])
        {
            visited[ni][nj] = true;
            dfs(ni,nj,path + movechar[k]);
            visited[ni][nj] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin  >> n;
        for(int i = 0; i<n; i++)
            for(int j = 0; j< n; j++)
                cin >> a[i][j];
        
        memset(visited, false, sizeof(visited));
        tmp.clear();
        
        if(a[0][0] == 1)
        {
            visited[0][0] = true;
            dfs(0,0,"");
        }

        if(tmp.empty())
        {
            cout << -1 << "\n";
        }
        else
        {
            sort(tmp.begin(), tmp.end());
            for(string s: tmp)
            {
                cout << s <<" ";
            }
        }
        cout << "\n";
    }
    return 0;
}