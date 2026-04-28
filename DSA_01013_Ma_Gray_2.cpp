#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string g;
        cin >> g;
        string b ="";
        b += g[0];

        for(int i = 1; i< g.size(); i++)
        {
            if(b[i-1] == g[i])
            {
                b +='0';
            }
            else
            {
                b += '1';
            }
        }

        cout << b << "\n";
    }
    return 0;
}