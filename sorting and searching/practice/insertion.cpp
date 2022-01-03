#include <iostream>
using namespace std;

void swap(int ar[], int i, int j)
{
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}
bool isSmaller(int ar[], int i, int j)
{
    if(ar[i] < ar[j])
        return true;
    
    return false;
}
void insertion(int ar[], int n)
{
    
    for(int i=1;i<n;i++)
    {
        int temp = ar[i];
        int j = i-1;
        while(j>=0)
        {
            if(isSmaller(ar, j+1 , j))
            {
                swap(ar, j, j+1);
            }
            j--;
        }
        ar[j] = temp;
    }
}
int main()
{
    int ar[] = {1, 6, 8, 12, 2, 9, 4, 6, 89, 100, 20, 15};
    int n = sizeof(ar) / sizeof(int);
    insertion(ar, n);
    for(int i=0; i<n;i++)
    {
        cout << ar[i] << " ";
    }
    return 0;
}