#include <bits/stdc++.h>
using namespace std;

void merge(vector <int> &ar, int s, int e)
{
    int i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;
    vector <int> v;

    while(i <= mid and j <= e){
        if(ar[i] < ar[j]){
            v.push_back(ar[i]);
            i++;
        }
        else{
            v.push_back(ar[j]);
            j++;
        }
    }
    while(i <= mid){
        v.push_back(ar[i++]);
    }
    while(j <= e){
        v.push_back(ar[j++]);
    }
    int k = 0;
    for(int p=s; p <= e; p++)
    {
        ar[p] = v[k++];
    }
    // return;
}
// void merge(vector <int> &ar, int s, int m, int e)
// {
//     vector <int> v;
//     int i = s;
//     int j = m + 1;
//     while(i <= m and j <= e)
//     {
//         if(ar[i] < ar[j])
//         {
//             v.push_back(ar[i++]);
//         }
//         else
//         {
//             v.push_back(ar[j++]);
//         }
//     }
//     while(i<= m)
//     {
//         v.push_back(ar[i++]);
//     }
//     while(j<= e)
//     {
//         v.push_back(ar[j++]);
//     }
//     int k = 0;
//     for(int idx= s; idx <= e;idx++)
//     {
//         ar[idx] = v[k++];
//     }
// }
void mergesort(vector <int> &ar, int start, int end)
{
    if(start < end)
    {
        int mid = start + (end-start) / 2;
        mergesort(ar, start, mid);
        mergesort(ar, mid + 1, end);
        merge(ar, start, end);
    }
}
int main()
{
    vector <int> ar {3, 5, 10, 12, 4, 2, 11, 64, 24};
    int n = ar.size();
    int s = 0;
    mergesort(ar, s, n);
    for(auto x: ar)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// void merge(vector <int> &ar,int mid, int s, int e)
// {
//     int i = s;
//     int j = mid + 1;
//     int k=s;
//     int v[100];

//     while(i <= mid and j <= e){
//         if(ar[i] < ar[j]){
//             v[k]=ar[i];
//             i++;
//             k++;
//         }
//         else{
//             v[k]=ar[j];
//             j++;
//             k++;
//         }
//     }
//     while(i <= mid){
//         v[k]=ar[i];
//         k++;
//         i++;
//     }
//     while(j <= e){
//         v[k]=ar[j];
//         k++;
//         j++;
//     }

//     for(int p=s; p <= e; p++)
//     {
//         ar[p] = v[p];
//     }
//     // return;
// }
// void mergesort(vector <int> &ar, int start, int end)
// {
//     if(start < end)
//     {
//     int mid = start +(end-start) / 2;
//     mergesort(ar, start, mid);
//     mergesort(ar, mid + 1, end);
//     merge(ar, mid, start, end);
//     }
// }

// int main()
// {
//     vector <int> ar {3, 5, 10, 12, 4, 2, 11, 64, 24};
//     int n = ar.size() - 1;
//     int s = 0;
//     mergesort(ar, s, n);
//     for(auto x: ar)
//     {
//         cout << x << " ";
//     }
//     cout << endl;
//     return 0;
// }