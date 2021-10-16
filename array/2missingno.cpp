#include<bits/stdc++.h>
using namespace std;

void missing(int ar[], int n)
{
    vector<bool> arr(n+1, false); 
    for(int i=0;i<n-2;i++)
    {
        arr[ar[i]] = true;
    }
    for(int i=1;i<=n;i++)
    {
        if(!arr[i])
            cout << i <<" ";
    }
}


int main()
{
    int ar[] = {1,2,4,5,6,8,9};
    int n = *(&ar + 1) - ar;
    missing(ar , n);
    return 0;
}