#include<bits/stdc++.h>
using namespace std;

// int pow(int r, int val)
// {
//     if(val == 1)
//         return r;
//     return r* pow(r, val -1);
// }
int pow(int r, int val)
{
    if(val == 0)
        return 1;
    if(val & 1)
        return val * pow(r, val/2) *pow(r, val/2);
    return pow(r, val/2) * pow(r, val/2);
}
double nthval(double sec, double th, int n)
{
    double r = th/sec;
    double a = sec/r;
    return (a * pow(r, n-1));
}
int main()
{
    double sec, th;
    int n;
    cin >> sec >> th >> n;
    cout << nthval(sec, th, n);
    return 0;
}