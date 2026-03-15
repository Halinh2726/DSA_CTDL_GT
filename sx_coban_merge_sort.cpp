#include<bits/stdc++.h>
using namespace std;

vector<int> combine(vector<int> a, vector<int> b)
{
    vector<int> ans;
    int n_a = a.size(), n_b = b.size();
    ans.reserve(n_a + n_b);

    int i = 0, j= 0;
    while(i < n_a && j < n_b)
    {
        if(a[i] == b[j])
        {
            ans.push_back(a[i]);
            ans.push_back(b[j]);
            j++;i++;
        }
        else if(a[i] < b[j])
        {
            ans.push_back(a[i]);
            i++;
        }
        else
        {
            ans.push_back(b[j]);
            j++;
        }
    }
    while(i < n_a){
        ans.push_back(a[i]);
        i++;
    }
    while(j < n_b)
    {
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}

void combine2(int a[], int l, int m, int r)
{
    vector<int> x(a+l,a+m+1);
    vector<int> y(a+m+1, a+r+1);
    int i = 0, j = 0;
    while(i < x.size() && j < y.size())
    {
        if(x[i] <= y[j])
        {
            a[l] = x[i];
            l++;
            i++;
        }
        else 
        {
            a[l] = y[j];
            l++;
            j++;
        }
    }
    while(i< x.size())
    {
        a[l] = x[i];
        l++;
        i++;
    }
    while(j< y.size())
    {
        a[l] = y[j];
        l++;
        j++;
    }
}
void mergesort(int a[], int l, int r)
{
    if( l< r)
    {
        int m = (l+r) / 2;
        mergesort(a,l,m);
        mergesort(a,m+1, r);
        combine2(a,l,m,r);
    }
}
int main()
{
    vector<int> a ={3,27,38,43};
    vector<int> b = {9, 10, 82};
    vector<int> c = combine(a,b);
    for(auto i: c) cout << i << " ";
    cout << "\n";
}

