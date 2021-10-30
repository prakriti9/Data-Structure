// Array is sorted

#include <iostream>
using namespace std;

int sortedduplicate(int ar[], int n)
{
    int i=0;
    int j=1;
    int count = 1;
    while(j<n)
    {
        if(ar[i] != ar[j])
        {
            swap(ar[++i], ar[j]);
            count++;
        }
        j++;
    }
    return count;
}
int main()
{
    int ar[] = {0,0,1,1,1,2,2,3,3,4};
    int  n = sizeof(ar)/sizeof(int);
    cout <<sortedduplicate(ar, n); 
    return 0;
}