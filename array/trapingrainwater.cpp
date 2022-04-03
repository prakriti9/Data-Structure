#include <iostream>
#include <algorithm>
using namespace std;
int rainwater(int ar[], int n)
{
    int ans = 0;
    int first[n], second[n];
    first[0] = ar[0];
    for(int i=1; i<n;i++)
    {
        first[i] = max(first[i-1], ar[i]);
    }
    second[n-1] = ar[n-1];
    for(int i=n-2; i>=0; i--)
    {
        second[i] = max(second[i+1], ar[i]);
    }
    for(int i=0; i<n;i++)
    {
        ans += min(first[i], second[i]) - ar[i];
    }
    cout << endl;
    return ans;
}
int main()
{
    int ar[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(ar) / sizeof(int);
    
    cout << rainwater(ar, n);
    return 0;
}