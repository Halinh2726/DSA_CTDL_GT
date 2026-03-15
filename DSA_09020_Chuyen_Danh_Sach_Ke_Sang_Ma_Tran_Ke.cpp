#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    int a[1001][1001] = {0};

    cin >> n;
    cin.ignore();
    for(int i = 1; i<= n; i++)
    {
        string s, num;
        getline(cin,s);
        stringstream ss(s);

        while(ss >> num)
        {
            a[i][stoi(num)] = 1;
            a[stoi(num)][i] = 1;
        }
    }

    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j <=n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout <<"\n";
    }
    return 0;
}