#include <iostream>
using namespace std;

// int pivotelement(int ar[], int n)
// {
//     int pos = -1;
//     for(int i=0;i<n;i++)
//     {
//         if(ar[i] > ar[i+1])
//         {
//             pos = i+1;
//         }
//     }
//     return pos;
// }
// int binarysearch(int arr[], int low,int high, int key)
// {
//     if (high < low)
//         return -1;
 
//     int mid = (low + high) / 2;
//     if (key == arr[mid])
//         return mid;
 
//     if (key > arr[mid])
//         return binarysearch(arr, (mid + 1), high, key);
 
//     return binarysearch(arr, low, (mid - 1), key);
// }
// int findelement(int ar[], int n, int k)
// {
//     int start = 0;
//     int end = n-1;
//     int res = -1;
//     int pivot = pivotelement(ar, n);
//     if(ar[0] > k)
//     {
//         return binarysearch(ar, pivot , n , k);
//     }
    
//     return binarysearch(ar, 0, pivot-1, k);
       
// }

int findelement(int ar[], int n, int k)
{
    int start = 0, end = n-1, mid;
    while(start <= end)
    {
        mid = start + (end  - start)/2;
        if(ar[mid] == k)
            return mid;

        else if(ar[mid] >= ar[start])
        {
            if(k <= ar[mid] and k >= ar[start])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else
        {
            if(k >= ar[mid] and k <= ar[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int k;
    cin >> k;
    int ar[] = {11, 12, 15, 18, 2, 5, 6, 8};
    int n = sizeof(ar)/sizeof(int);
    cout << findelement(ar, n , k)<< endl;
   return 0; 
} 

