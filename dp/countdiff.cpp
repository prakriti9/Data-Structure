#include <bits/stdc++.h>
using namespace std;

// int helperset(int ar[], int n, int sum, int diff)
// {
//     int dp[n + 1][sum + 1];
//     for(int i=0; i<=n;i++) dp[i][0] = 1;
//     for(int i=0; i<=n;i++)
//     {
//         for(int j=1; j<=sum; j++)
//         {
//             dp[i][j] = 0;
//         }
//     }
//     for(int i=1; i<=n;i++)
//     {
//         for(int j=1; i<=sum; j++)
//         {
//             if(j < ar[i-1])
//             {
//                 dp[i][j] = dp[i-1][j];
//             }
//             else
//             dp[i][j] = dp[i-1][j] + dp[i-1][j-ar[i-1]];
//         }
//     }
//     return dp[n][sum];
// }
int dp[102][1002];
int f(int ind, int sum )
int countdiffer(int ar[], int n, int diff)
{
    int sum =0;
    for(int i=0; i<n;i++)
        sum += ar[i];
    if (sum - diff < 0 || (sum - diff) % 2 == 1) {
        return 0;
    }
    return helperset(ar, n, (sum - diff)/2, diff);
    
}
int main()
{
    int ar[] = {1, 1, 2, 3};
    int n = sizeof(ar) / sizeof(int);
    int diff = 1;
    cout << countdiffer(ar, n, diff);
    return 0;
}