// to find the no. of digits
#include <bits/stdc++.h>
using namespace std;
int findgigits(int n)
{
    int count = 0;
    int i = 0;
    while(i <= n)
    {
        count++;
        n = n / 10;
        i++;
    }
    return count + 1;
}
int main()
{
    int n;
    cin >> n;
    // cout << findgigits(n) << endl;
    cout << floor(log10(n) + 1) << endl;
    return 0;
}