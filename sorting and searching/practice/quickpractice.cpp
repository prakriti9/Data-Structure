#include <iostream>
#include <vector>
using namespace std;

int partition(vector <int> &v, int s, int e)
{
    int pivot = v[e];
    int i = s - 1;
    for(int j = s; j <= e;j++)
    {
        if(v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[e]);
    return i+1;

}
void quicksort(vector <int> &v, int s, int e)
{
    if(s < e)
    {
        int p = partition(v, s, e);
        quicksort(v, s, p-1);
        quicksort(v, p+1, e);
    }
}
int main()
{
    vector <int> v {10, 29, 2, 7, 1, 6, 23, 3, 11, 6, 9};
    int n = v.size();
    quicksort(v, 0, n-1);
    for(int i = 0; i< n;i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}