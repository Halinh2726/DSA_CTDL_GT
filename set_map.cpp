#include<bits/stdc++.h>
using namespace std;

// Lop Container

/*
Con chay Iterator
*/

// int main()

// {
//     set<int> mySet;
//     set<int>::iterator i;
//     mySet.insert(3);
//     mySet.insert(1);
//     mySet.insert(3);
//     mySet.insert(2);
//     for(i = mySet.begin(); i != mySet.end(); i++)
//     {
//         cout << *i << " ";
//     }
// }


int n, q, a[100005];
set<int> s;

int main()
{
    cin >> n;
    for(int i= 1; i<= n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;
        if(s.find(x) != s.end())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}