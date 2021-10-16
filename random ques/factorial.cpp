// to find the factorial
#include <bits/stdc++.h>
using namespace std;

// int fact(int n)
// {
//     int ft = 1;
//     for(int i = 2;i <= n;i++)
//     {
//         ft = ft*i;
//     }
//     return ft;
// }

// int fact(int n)
// {
//     if(n == 1)
//         return n;
//     return n * fact (n-1);
// }
int main()
{
    int n;
    cin >> n;
    
    cout << fact(n) << endl;
    return 0;
}