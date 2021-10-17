#include <iostream>
#include <vector>
#include <set>
using namespace std;

// vector<int> unionval(int ar1[], int ar2[], int n , int m)
// {
//     vector <int> v;
//     int i=0,j=0;
//     while(i<n && j<m)
//     {
//         if(ar1[i] == ar2[j])
//         {
//             v.push_back(ar1[i]);
//             i++;
//             j++;
//         }
//         else if(ar1[i] > ar2[j])
//         {
//             v.push_back(ar2[j]);
//             j++;
//         }
//         else
//         {
//             v.push_back(ar1[i]);
//             i++;
//         }
//     }
//     while(i<n)
//     {
//         v.push_back(ar1[i++]);
//     }
//     while(j<m)
//     {
//         v.push_back(ar2[j++]);
//     }
//     return v;
// }
void unionval(int ar1[], int ar2[], int n , int m)
{
    set <int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(ar1[i]);
    }
    for(int i=0;i<m;i++)
    {
        s.insert(ar2[i]);
    }
    for(auto x: s)
    {
        cout << x<< " ";
    }
}
int main()
{
    int n, m;
    cin>> n>> m;
    int ar1[n], ar2[m];
    for(int i=0;i<n;i++)
    {
        cin >> ar1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin >> ar2[i];
    }
    unionval(ar1, ar2, n, m);
    // vector <int> v = unionval(ar1, ar2, n, m);
    // for(int i=0;i<v.size();i++)
    // {
    //     cout << v[i] << " ";
    // }
    return 0;
} 
