#include <bits/stdc++.h>
using namespace std;

int dp[102][1002];
int knapsack(int wt[],int pf[], int totalweight, int n)
{
    memset(dp, -1, sizeof(dp));
    if(n == 0 || totalweight == 0)
        return 0;
    
    if(dp[n][totalweight] != -1) return dp[n][totalweight];
    if(totalweight < wt[n-1])
    {
        return dp[n][totalweight] = knapsack(wt, pf, totalweight, n-1);
    }
    else if(totalweight >= wt[n-1])
    {
        int ch1 = pf[n-1] + knapsack(wt, pf, totalweight - wt[n-1], n-1);
        int ch2 = knapsack(wt, pf, totalweight, n-1);
        return dp[n][totalweight] = max(ch1, ch2);
    }return dp[n][totalweight];
}
int main()
{
    int pf[] = {60, 100, 120};
    int wt[] = {10, 20, 30 };
    int n = sizeof(wt) / sizeof(int);
    int totalweight = 50;
    cout << knapsack(wt, pf, totalweight, n);
    return 0;
}