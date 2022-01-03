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
void bubble(int ar[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<n-i-1;j++)
        {
            if(isSmaller(ar, j+1, j))
                swap(ar, j, j+1);
        }
    }
}
int main()
{
    int ar[] = {1, 6, 8, 12, 2, 9, 4, 6, 89, 100, 20, 15};
    int n = sizeof(ar) / sizeof(int);
    bubble(ar, n);
    for(int i=0; i<n;i++)
    {
        cout << ar[i] << " ";
    }
    return 0;
}