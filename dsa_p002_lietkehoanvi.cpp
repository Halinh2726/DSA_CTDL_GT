#include<bits/stdc++.h>
using namespace std;

int n, ok = 1;
int a[100];
int cnt = 1;
void Khoitao()
{
    for(int i = 0; i<n; i++)
    {
        a[i] = i+1;
    }
}

void Inkq()
{

    cout << cnt++ << ": ";
    for(int i  = 0; i< n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void Try()
{
    int i = n-2;

    while(i>= 0 && a[i] >= a[i+1])
    {
        i--;
    }
    if(i < 0){
        ok = 0;
        return;
    }
    else
    {
        int j = n-1;
        while(a[i] >= a[j])
            j--;
        swap(a[i], a[j]);
        reverse(a+i+1, a+n);
    } 
}


int main()
{
    cin >> n;
    Khoitao();
    Inkq();
    while(ok)
    {
        Try();
        if(ok) Inkq();
    }
    return 0;
}
