// to find the trailing zero
#include <bits/stdc++.h>
using namespace std;

int trailingzero(int n)
{
    int res = 0;
    for(int i =5; i<= n;i= i*5)
    {
        res = res +n/i;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    cout << trailingzero(n) << endl;
    return 0;
}