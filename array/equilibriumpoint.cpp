#include <iostream>
using namespace std;

int equilibrium(int ar[], int n)
{
    int sumar[n];
    int sum = 0;
    for(int i=0; i<n;i++)
    {
        sum += ar[i];
        sumar[i] = sum;
    }
    if(n == 1)
        return 0;
    if(n == 2)
        return -1;
    // for(int i=0; i<n;i++)
    // {
    //     cout << sumar[i] << " ";
    // }

    int total = sumar[n-1];
    int l , r;
    for(int i=1; i<n;i++)
    {
        l = sumar[i] - ar[i];
        r = total - sumar[i];
        if(l == r)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int ar[] = {1, 2, 6, 4, 0, -1};
    int n = sizeof(ar) / sizeof(int);
    cout << equilibrium(ar, n);
    return 0;
}