#include<bits/stdc++.h>
using namespace std;

void Try(int n, char a, char b, char c)
{
    // a: from
    // b: mid
    // c: to
    if(n == 1)
    {
        cout << a << " -> " << c << "\n";
        return;
    }

    Try(n-1,a,c,b); // chuyen n-1 dia tu a sang b
    Try(1,a,b,c); // chuyen 1 dia tu a sang c
    Try(n-1,b,a,c); // chuyen n-1 dia tu b sang c
}

int main()
{
    int n; cin >> n;
    Try(n, 'A','B', 'C');
    cout << "\n";
    return 0;
}