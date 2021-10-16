#include<iostream>
using namespace std;

int firstpos(int ar[], int start, int end, int k)
{
    int mid = (start + end)/2;
    if(ar[mid] < k)
    {
        return firstpos(ar, mid + 1, end, k);
    }
    else if(ar[mid] > k)
    {
        return firstpos(ar, start, mid - 1, k);
    }
    else{
        if(mid == 0 || ar[mid-1] != ar[mid])
            return mid;
        return firstpos(ar, start, mid - 1, k);
    }
    return -1;
}
int lastpos(int ar[], int start, int end, int k)
{
    int mid = (start + end)/2;
    if(ar[mid] < k)
    {
        return lastpos(ar, mid + 1, end, k);
    }
    else if(ar[mid] > k)
    {
        return lastpos(ar, start, mid - 1, k);
    }
    else
    {
        if(mid == end-1 || ar[mid+1] != ar[mid])
            return mid;
        return lastpos(ar, mid + 1, end, k);
    }
}
int main()
{
    int ar[] = {1,2,3,4,4,4,4,5,5,6};
    int n = *(&ar + 1) - ar;
    cout << firstpos(ar, 0, n, 5)<< endl;
    cout << lastpos(ar, 0, n, 5) << endl;
    return 0;
}