#include<bits/stdc++.h>
using namespace std;

// void bubblesort(int a[], int n)
// {
//     for(int i = 0; i< n-1; i++)
//     {
//         for(int j = 0; j< n; j++)
//         {
//             if(a[i] < a[j])
//             {
//                 swap(a[i], a[j]);
//             }
//         }
//     }
// }

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n; 
        int a[n];
        for(int i =0; i< n; i++)
        {
            cin >> a[i];
        }
        sort(a,a+n);
        for(int i = 0; i< n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}