#include <bits/stdc++.h>
using namespace std;
int dp[102][1002];
int countsubset(int ar[], int n, int sum)
{
	memset(dp, -1, sizeof(dp));
    if(sum == 0)    return 1;
    if(n<=0 and sum != 0) return 0;

	if(dp[n][sum] == -1)
	{
		if(sum < ar[n-1])
			return dp[n-1][sum] = countsubset(ar, n-1, sum);
		else if(sum >= ar[n-1])
		{
			int f1 = countsubset(ar, n - 1, sum-ar[n-1]);
			int f2 = countsubset(ar, n-1, sum);
			return dp[n-1][sum] = f1 + f2;
		}
	}
	return dp[n-1][sum];
}


// int countsubset(int arr[], int n, int sum)
// {
// 	int dp[n+1][sum+1];

// 	for(int i=0; i<=n; i++) dp[i][0] = 1;
// 	for(int j=1; j<=sum; j++) dp[0][j] = 0;


// 	for(int i=1; i<=n; i++)
// 	{
// 		for(int j=0; j<=sum; j++)
// 		{
// 			if(j < arr[i-1])
// 				dp[i][j] = dp[i-1][j];
// 			else if(j >= arr[i-1])
// 				dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
// 		}	
// 	}

// 	return dp[n][sum];
// }
int main()
{
    int ar[] = {1, 2, 3, 4, 5};
    int n = sizeof(ar) / sizeof(int);
    int sum = 10;
    cout << countsubset(ar, n, sum);
    return 0;
}