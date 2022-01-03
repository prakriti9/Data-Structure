#include <iostream>
using namespace std;


int leftmost(int ar[], int start, int end, int k)
{
    int mid = start + (end - start)/2;
    if(ar[mid] < k)
        return leftmost(ar, mid + 1, end, k);
    else if(ar[mid] > k)
        return leftmost(ar, start, mid - 1, k);
    else
    {
        if(mid == 0|| ar[mid - 1] != ar[mid])
            return mid;
        return leftmost(ar, start, mid - 1, k);
    }
    return -1;
}
int rightmost(int ar[], int start, int end, int k)
{
    int mid = start + (end - start)/2;
    if(ar[mid] < k)
        return rightmost(ar, mid + 1, end, k);
    else if(ar[mid] > k)
        return rightmost(ar, start, mid - 1, k);
    else
    {
        if(mid == end - 1|| ar[mid + 1] != ar[mid])
            return mid + 1;
        return rightmost(ar, mid + 1, end, k);
    }
    return -1;
}
int countfrequency(int ar[], int n, int k)
{
    return rightmost(ar, 0, n, k) - leftmost(ar, 0, n, k);
}
int main()
{
    int ar[] = {0,1,1,1,1,2,2,2,3,4,5,5};
    int n = sizeof(ar)/ sizeof(int);
    cout << leftmost(ar, 0, n, 15);
    // cout << countfrequency(ar, n, 15);
    return 0;
}