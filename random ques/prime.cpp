// to find the no. prime
#include <bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
    if(n < 2)
        return true;
    for(int i = 2; i < n;i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    if(isprime(n))
    {
        cout << "PRIME";
    }
    else{
        cout << "NOT PRIME";
    }
    return 0;
}