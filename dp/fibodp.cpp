#include <bits/stdc++.h>
using namespace std;
// top down approach
// int fibo(int n)
// {
//     int d[n+1] = {-1};
//     memset(d, -1, sizeof(d));
//     if(d[n] != -1) return d[n];
//     else
//     {
//         if(n==0 || n==1) return n;
//         else
//         return d[n] = fibo(n-1) + fibo(n-2);
//     }
//     return 0;
// }

// bottom up approach

int fibo(int n)
{
    int dp[n+1];
    dp[0] =0 ; dp[1] = 1;
    // int a, b;
    if(n== 0 or n==1) return dp[n];
    for(int i=2; i<=n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];

}
int main()
{
    int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}