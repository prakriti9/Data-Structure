#include <bits/stdc++.h>
using namespace std;
void merge(int ar1[], int ar2[], int n, int m)
{
    int i = n-1, j = 0;
    while(i>=0 and j<m)
    {
        if(ar1[i] >= ar2[j])
        {
            swap(ar1[i], ar2[j]);
            i--;
            j++;
        }
        else
        {
            break;
        }
    }
    sort(ar1 , ar1 + n);
    sort(ar2 , ar2 + m);
}
int main()
{
    int n, m;
    cin >> n >>m;
    int ar1[n], ar2[m];
    for(int i = 0;i < n; i++)
    {
        cin >> ar1[i];
    }
    for(int i = 0;i < m; i++)
    {
        cin >> ar2[i];
    }

    merge(ar1, ar2, n, m);
    for(int i = 0;i < n; i++)
    {
        cout << ar1[i] <<" ";
    }
    for(int i = 0;i < m; i++)
    {
        cout << ar2[i] <<" ";
    }
    return 0;
}