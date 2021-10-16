#include<iostream>
using namespace std;

// O(n)
// void firstlastocc(int ar[], int n, int x)
// {
//     for(int i=0;i<n;i++)
//     {
//         if(ar[i] != x and ar[i+1] == x)
//         {
//             cout << i+1 <<" ";
//         }
//         if(ar[i+1]!= x and ar[i] == x)
//         {
//             cout<<i<<" ";
//             break;
//         }
//     }
// }
// O(logn)
void firstocc(int ar[], int n, int x)
{
    int firstval = -1;
    int i=0 , j = n-1;
    while(i <= j)
    {
        int mid = (i+j)/2;
        if(ar[mid] >= x)
        {
            j = mid -1;
        }
        else
        {
            i = mid + 1;
        }
        if(ar[mid] == x)
        {
            cout << mid << " ";
        }
    }
}

void lastocc(int ar[], int n, int x)
{
    int lastval = -1;
    int i=0, j = n-1;
    while(i<=j)
    {
        int mid = (i+j)/2;
        if(ar[mid] >= x)
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
        if(ar[mid] == x)
        {
            cout << mid <<" "; 
        }
    }
}
int main()
{
    int ar[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125};
    int n = sizeof(ar)/sizeof(int);
    int x = 7;
    firstocc(ar , n, x);
    lastocc(ar, n, x);
    return 0;
}