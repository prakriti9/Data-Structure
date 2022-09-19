#include <bits/stdc++.h>
using namespace std;

// int minimumsteps(int n, int dp[])
// {
//     if(n == 1) return 0;
//     int op1,op2, op3;
//     op1 = op2 = op3 = INT_MAX;
//     if(dp[n] != -1) return dp[n];
//     if(n%3 == 0)
//     {
//         op3 = minimumsteps(n/3, dp) + 1;
//     }
//     if(n % 2 == 0) 
//     {
//         op2 = minimumsteps(n/2, dp) + 1;
//     }
//     op1 = minimumsteps(n-1, dp) + 1;
//     int ans = min(op1, min(op2, op3));
//     return dp[n] = ans;
// }
int minstep(int n)
{
    int dp[100] = {0};
    dp[1] = 0;
    for(int i=2; i<=n;i++)
    {
        int val1, val2, val3;
        val1 = val2 = val3 = INT_MAX;
        if(i%3 == 0)
            val1 = dp[i/3] + 1;
        if(i%2 == 0)
            val2 = dp[i/2] + 1;
        val3 = dp[i-1] + 1;
        dp[i] = min(val1, min(val2, val3));
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    int dp[n+1];
    memset(dp, -1, sizeof(dp));
    cout << minstep(n);
    return 0;
}