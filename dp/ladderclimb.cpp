#include <bits/stdc++.h>
using namespace std;

int ladder(int n, int k)
{
    int ans = 1;
    if(n==0) return 1;
    if(n < 0) return 0;
    for(int i=1; i<=n;i++)
    {
        ans += ladder(n - i, k);
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << ladder(n, k);
    return 0;
}