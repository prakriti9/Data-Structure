#include <bits/stdc++.h>
using namespace std;

int dp[100][1002];
bool subset(int n, int set[], int sum)
{
    memset(dp, -1, sizeof(dp));
    if(sum == 0)
        return true;
    else if(n == 0) return false;
    if(dp[n][sum] == -1) 
    {
        if(set[n-1] <= sum)
        {
            return dp[n][sum] = subset(n-1, set, sum-set[n-1]) || subset(n-1, set, sum);
        }
        else if(set[n-1] > sum)
        {
            return dp[n][sum] = subset(n-1, set, sum);
        }
    }
    return dp[n][sum];
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2}, sum = 48;
    int n = sizeof(set) / sizeof(int);
    cout << subset(n, set, sum);
    return 0;
}