#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n1,n2,n3;
        cin >> n1 >> n2 >> n3;
        vector<long long> a(n1), b(n2), c(n3);
        for(int i = 0; i< n1; i++) cin >> a[i];
        for(int i = 0; i< n2; i++) cin >> b[i];
        for(int i = 0; i< n3; i++) cin >> c[i];

        int check = 0;
        long long i = 0, j = 0, l = 0;
        while(i < n1 && j < n2 && l < n3)
        {
            if(a[i] == b[j] && a[i] == c[l])
            {
                cout << a[i] << " ";
                check = 1;
                i++; j++; l++;
            }
            else{
                long long min_x = min({a[i], b[j], c[l]});
                if(a[i] == min_x) i++;
                if(b[j] == min_x) j++;
                if(c[l] == min_x) l++;
            }
        }
        if(!check) cout << "-1\n";
        cout << "\n";
    }
    return 0;
}