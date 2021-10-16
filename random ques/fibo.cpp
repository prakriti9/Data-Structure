// to find the fibnnoci
#include <bits/stdc++.h>
using namespace std;

// int fibo(int n)
// {
//     int a = 0;
//     int b = 1;
//     int c;
//     for(int i =2; i<= n; i++)
//     {
//         c = a+ b;
//         a = b;
//         b = c;
//     }
//     return c;
// }

// int fibo(int n)
// {
//     if(n ==0 || n == 1)
//         return n;
//     return fibo(n-1) + fibo(n-2);

// }

// Dynamic Programming
int fibo(int n)
{
    int f[n+1];
    f[0] = 0;
    f[1] = 1;
    for(int i = 2;i<= n;i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}
int main()
{
    int n;
    cin >> n;
    
    cout << fibo(n) << endl;
    return 0;
}