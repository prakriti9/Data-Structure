// sort 0 , 1 , 2
#include <bits/stdc++.h>
using namespace std;

void sort(int ar[], int n)
{
    int i = 0;
    int j = n-1;
    int mid = 0;
    while(mid <= j)
    {
        switch (ar[mid])
        {
        case 0: swap(ar[i++], ar[mid++]);
            break;
        
        case 1: mid++;
            break;
        case 2: swap(ar[j--], ar[mid]);
            break;
        }
    }
}
int main()
{
    int ar[] = {0,1,1,2,0,0,0,1,1,2,1,2};

    int n = *(&ar + 1) - ar;
    sort(ar, n);
    for(int i = 0; i < n;i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
    return 0;
}