#include <bits/stdc++.h>
using namespace std;

int helpersubsetsim(int ar[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    for(int i=0; i<=n;i++) dp[i][0] = 1;
    for(int i=0; i<=n;i++)
    {
        for(int j=1; j<=sum; j++) 
            dp[i][j] = 0;
    }
    for(int i=1; i<= n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(j < ar[i-1])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j - ar[i - 1]];
            }
        }
    }
    vector <int> v;
    for(int j=0; j<=sum/2; j++)
    {
        if(dp[n][j] == 1)
        {
            v.push_back(j);
        }
    }
    int val = v[v.size()-1];
    
    return sum - 2 * val;
}

int minivalue(int ar[], int n)
{
    int sum = 0;
    for(int i=0; i<n;i++)
        sum += ar[i];

    return helpersubsetsim(ar, n, sum);
}
int main()
{
    int arr[] = {1, 4 };
    int n = sizeof(arr) / sizeof(int);
    cout << minivalue(arr, n);
    return 0;

}