#include<bits/stdc++.h>
using namespace std;

int n,k;
int ok = 1;
vector<int> a(100);
void KhoiTao()
{
    for(int i = 0; i< k; i++)
    {
        a[i] = i+1;
    }
}

void Sinh_to_hop()
{
    int i = k -1;
    while(i>= 0 && a[i] == n-k+i+1)
    {
        i--;
    }
    if(i < 0) ok = 0;
    else{
        a[i]++;
        for(int j = i+1; j < k; j++)
        {
            a[j] = a[j-1] + 1;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        KhoiTao();

        while(ok)
        {
            for(int i = 0; i< k; i++)
            {
                cout << a[i];
            }
            cout << " ";
            Sinh_to_hop();
        }
        ok = 1;
        cout <<"\n";
    }
    return 0;
}