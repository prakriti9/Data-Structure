#include <bits/stdc++.h>
using namespace std;

bool armstrong(int n)
{
    int sum = 0;
    int num = n;
    while(num!=0)
    {
        int rem = num%10;
        sum += rem*rem*rem;
        num = num/10;
    }
    if(n == sum)
        return true;
    return false;
}
int main()
{
    int num;
    cin>> num;
    if(armstrong(num))
    {
        cout << "armstrong";
    }
    else
    {
        cout <<"not armstrong";
    }
    return 0;
}