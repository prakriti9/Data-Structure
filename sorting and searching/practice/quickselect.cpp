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
int quickselect(vector <int> &v, int s, int e, int pos)
{  
    int p = partition(v, s, e);
    if(pos == p)
        return v[p];
    if(pos > p)
    {
        return quickselect(v, s, p+1, pos);
    }
    else
    {
        return quickselect(v, s, p-1, pos);
    }
}
int main()
{
    vector <int> v {10, 8, 4, 2, 3, 0};
    int n = v.size();
    int pos = 4;
    cout << quickselect(v, 0, n-1, pos) << endl;
    quicksort(v, 0, n-1);
    for(int i = 0; i< n;i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}