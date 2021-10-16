#include <bits/stdc++.h>
using namespace std;

void negativeoneside(int ar[], int n)
{
    int i = 0;
    int j = n-1;
    while(i<=j)
    {
        if(ar[j] < 0)
        {
            swap(ar[i++], ar[j]);
        }
        else
        {
            j--;
        }
    }
}
int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr) /sizeof(arr[0]);
    negativeoneside(arr, n);
    for(int i=0; i<n;i++)
    {
        cout << arr[i] <<" ";
    }
    return 0;
}