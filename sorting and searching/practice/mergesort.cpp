#include <iostream>
#include <vector>
using namespace std;

void merge(vector <int> &ar, int s, int m, int e)
{
    vector <int> v;
    int i = s, j = m + 1;
    while(i <= m and j <= e)
    {
        if(ar[i] < ar[j])
        {
            v.push_back(ar[i++]);
        }
        else
        {
            v.push_back(ar[j++]);
        }
    }
    while(i <= m)
    {
        v.push_back(ar[i++]);
    }
    while(j <= e)
    {
        v.push_back(ar[j++]);
    }
    int k = 0;
    for(int p = s; p <= e; p++)
    {
        ar[p] = v[k++]; 
    }
    // for(int i = s; i <= e;i++)
    // {
    //     cout << ar[i] << " ";
    // }
    // cout << endl;
}
void mergesort(vector <int> &ar, int s, int e)
{
    if(s < e)
    {
        int m = s + (e - s) / 2;
        mergesort(ar, s, m);
        mergesort(ar, m + 1, e);
        merge(ar, s, m, e);
    }
    
}
int main()
{
    vector<int> ar = {1, 6, 8, 12, 2, 9, 4, 6, 89, 100, 20, 15};
    // int n = sizeof(ar) / sizeof(int);
    int n = ar.size();
    mergesort(ar, 0, n-1);
    for(auto x: ar)
    {
        cout << x << " ";
    }
    return 0;
}