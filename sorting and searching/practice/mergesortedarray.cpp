#include <bits/stdc++.h>
using namespace std;

void merge(int ar1[], int ar2[], int m, int n)
{
    int i = m - 1;
    int j = 0;
    while(i>=0 and j<n)
    {
        if(ar1[i] > ar2[j])
        {
            swap(ar1[i], ar2[j]);
            i--;
            j++;
        }
        else
            break;
    }
    sort(ar1, ar1 + m);
    sort(ar2, ar2 + n);
}
int main()
{
    int ar1[] = {1, 4, 5, 7, 10, 11};
    int ar2[] = {2, 3, 4, 6, 9, 12};
    int m = sizeof(ar1) / sizeof(int);
    int n = sizeof(ar2) / sizeof(int);
    merge(ar1, ar2, m, n);
    for(int i=0; i< m;i++)
    {
        cout << ar1[i] << " ";
    }
    for(int i = 0;i<n;i++)
    {
        cout << ar2[i] << " ";
    }
    
    return 0;
}