#include <iostream>
using namespace std;

// O(logn)
int binary(int ar[], int start, int end, int key)
{
    if(end >= start)
    {
        int mid =  start + (end - start)/2;
        if(ar[mid] == key)
        return mid;
    
        else if(ar[mid] < key)
        return binary(ar, mid + 1, end, key);  

     
        return binary(ar, start, mid - 1, key);
    }

    return -1;
}
int main()
{
   int ar[] = {1,2,3,4,5,6,7,8,9,10};
   int n = *(&ar + 1) - ar;
   cout << binary(ar, 0, n-1, 17);
   return 0; 
} 
