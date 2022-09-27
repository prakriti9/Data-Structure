#include <iostream>
#include <cstring>
using namespace std;

// recursion
// int unordered(int wt[], int val[], int W, int n)
// {
//     if(n==0 || W==0) return 0;
    
//     if(wt[n-1] > W)
//         return unordered(wt, val, W, n-1);
//     else
//     {
//         int choice1 = unordered(wt, val, W, n-1);
//         int choice2 = val[n-1] + unordered(wt, val, W-wt[n-1], n);
//         return max(choice1, choice2);
//     }
//     return unordered(wt, val, W, n-1);
// }

// memoization
// int dp[102][1002];
// int unordered(int wt[], int val[], int W, int n)
// {
//     memset(dp, -1, sizeof(dp));
//     for(int i=0; i<=n;i++) dp[i][0] =0;
//     for(int j=0; j<=W; j++) dp[0][j] = 0;

//     if(dp[n][W] == -1)
//     {
//         if(W < wt[n-1])
//         {
//             return dp[n][W] = unordered(wt, val, W, n-1);
//         }
//         else
//         {
//             int choice1 = unordered(wt, val, W, n-1);
//             int choice2 = val[n-1] + unordered(wt, val, W- wt[n-1], n);
//             return dp[n][W] = max(choice1, choice2);
//         }
//     }
//     else
//     return dp[n][W];  
// }
int unordered(int wt[], int val[], int W, int n)
{
    int dp[n+1][W+1];
    for(int i=0; i<=n;i++) dp[i][0] = 0;
    for(int j=0; j<=W;j++) dp[0][j] = 0;

    for(int i=1; i<=n;i++)
    {
        for(int j=1; j<=W; j++)
        {
            if(wt[i-1] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i][j- wt[i-1]]);
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int W = 8;
    int val[] = { 10, 40, 50, 70 };
    int wt[] = { 1, 3, 4, 5};
    int n = sizeof(val) / sizeof(val[0]);
    cout << unordered(wt, val, W, n);

    return 0;
}