#include <bits/stdc++.h>

using namespace std;

// int mincoins(int coins[], int n, int amount, int dp[])
// {
//     if(amount == 0) return 0;
//     if(dp[amount] != 0) return dp[amount];
//     int ans = INT_MAX;
//     for(int i=0; i<n;i++)
//     {
//         if(amount - coins[i] >= 0)
//         {
//             int subproblem = mincoins(coins, n, amount - coins[i], dp);
//             ans = min(ans, subproblem + 1);
//         }       
//     }
//     dp[amount] = ans;
//     return dp[amount];
// }

// bottom up approch
int mincoins(int coins[], int n, int amount, int dp[])
{
    dp[100] = {0};
    if(amount == 0) return 0;
    // if(dp[amount] != 0) return dp[amount];
    for(int i=1; i<= amount; i++)
    {
        dp[i] = INT_MAX;
        for(int t=0; t<n; t++)
        {
            if(amount - coins[t] >= 0)
            int sub = dp[amount - coins[t]];
            dp[t] = min(s)
        }
    }
}
int main()
{
    int coins[] = {1, 7, 10};
    int n = sizeof(coins) / sizeof(int);
    int num;
    cin >> num;
    int dp[100];
    memset(dp, 0, sizeof(dp));
    cout << mincoins(coins, n, num, dp);
    return 0;
}