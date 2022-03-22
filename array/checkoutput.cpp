#include <iostream>
#include <vector>
using namespace std;

// void fun()
// {
//     int count = 0;

//     for(int i=0; i<5; i++);
//     {
//         for(int j=0; j<10;j++)
//         {
//             count += 1;
//         }
//     }
//     cout << count << endl;
// }

void bubble(int ar[], int n)
{
    for(int i=0; i<n;i++)
    {
        for(int j =0; j<n-i-1; j++)
        {
            if(ar[j] > ar[j+1])
            {
                int temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = temp;
            }
        }
    }
}
void selection(int ar[], int n)
{
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n;j++)
        {
            if(ar[j] > ar[i])
            {
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
}

void insertion(int ar[], int n)
{
    int j;
    for(int i=1; i<n;i++)
    {
        int temp = ar[i];
        j = i-1;
        while(j>= 0 and ar[j] >= temp)
        {
            ar[j+1] = ar[j];
            j--;
        
        }
        ar[j+1] = temp;
    }
}

void merge(vector <int> v, int s, int e)
{
    int i = s;
    int m = (s+e) / 2;
    int j = m + 1;

    vector <int> temp;

    while(i<=m and j<=e)
    {
        
    }
    
}
void mergesort(vector <int> v, int s, int e)
{
    if(s < e)
    {
        int mid = (s + e) / 2;
        mergesort(v, s, mid);
        mergesort(v, mid + 1, e);
        merge(v, s, e);
    }
}
int main()
{
    vector <int> v = {4, 10, 7, 12, 11, 5, 12, 8, 1};
    // int n = sizeof(ar) / sizeof(int);
    // bubble(ar, n);
    // selection(ar, n);
    insertion(ar, n);
    for(int i=0; i<n;i++)
    {
        cout << ar[i] << " ";
    }
    return 0;
}