// Display minimum no. of coins
#include <bits/stdc++.h>
using namespace std;
int minicoins(int ar[],int n, int val)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        // int res;
        if(ar[i] <= val)
        {
            int res = floor(val/ ar[i]);
            count += res;
            val -= res * ar[i];  
        }
        if(val == 0)
            break;
    }
    return count;
}
int main()
{
    int coins[] = {2000, 500, 100, 50, 20, 10, 5, 2, 1};
    int n = *(&coins + 1) - coins;
    int val;
    cin >> val;
    cout << minicoins(coins, n, val);
    return 0;
}