#include <iostream>
#include <vector>
using namespace std;

vector<int> intersection(int ar1[], int ar2[], int n , int m)
{
    vector <int> v;
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(ar1[i] == ar2[j])
        {
            v.push_back(ar1[i]);
            i++;
            j++;
        }
        else if(ar1[i] > ar2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return v;
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
    vector <int> v = intersection(ar1, ar2, n, m);
    for(int i=0;i<v.size();i++)
    {
        cout << v[i] << " ";
    }
    return 0;
} 
