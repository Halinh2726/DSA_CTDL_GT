#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string b;
        cin >> b;
        string g ="";
        g += b[0];

        for(int i = 1; i< b.size(); i++)
        {
            if(b[i] == b[i-1]) g+= '0';
            else g += '1';
        }
        cout << g << "\n";
    }
    return 0;
}