#include<bits/stdc++.h>
using namespace std;

int n;
int a[105];
int sum;
int target;
int found;

void inkq()
{
    found = 1;
}

void Try(int i)
{
    if(found) return;
    if(sum == target)
    {
        inkq();
        return;
    }
    if(i == n || sum > target)
    {
        return;
    }

    //Chon
    sum += a[i];
    Try(i+1);
    sum -= a[i];

    // Khong chon
    Try(i+1);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int s =0;
        cin >> n;
        for(int i=  0; i< n; i++)
        {
            cin >> a[i];
            s+= a[i];
        }

        if(s%2 != 0)
        {
            cout << "NO\n";
            continue;
        }
        
        target = s/2;
        sum = 0;
        found = 0;
        Try(0);
        if(found)
        {
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
