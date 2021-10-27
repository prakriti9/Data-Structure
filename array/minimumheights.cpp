#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k,n;
    cin>>k;
    int arr[] = {1, 5, 8, 10};
    n = sizeof(arr)/sizeof(int);

    sort(arr, arr + n);
    int mini = arr[0];
    int maxi = arr[n-1];
    int ans = maxi - mini;
    
    int mi = 0, mx = 0;
    for(int i=1;i<n;i++)
    {
        mx = max(arr[i-1] + k, arr[n-1] - k);
        mi = min(arr[0] + k, arr[i] - k);
        
        if(mi < 0)
            continue;
        ans = min(ans, mx - mi);
    }
    cout << ans;
    return 0;
}