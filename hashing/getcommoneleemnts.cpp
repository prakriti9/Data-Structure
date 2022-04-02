#include <bits/stdc++.h>
using namespace std;

void commonelement(int ar1[], int m, int ar2[], int n)
{
    unordered_map<int, int>mp;
    for(int i=0;i<m;i++)
    {
        mp[ar1[i]]++;
    }
    set<int>s;
    for(int i=0; i<n;i++)
    {
        if(mp.find(ar2[i]) != mp.end())
        {
            if(s.find(ar2[i]) == s.end())
            {
                cout << ar2[i] << " ";
            }
        }
        s.insert(ar2[i]);
    }

}
void commonelement2(int ar1[], int m, int ar2[], int n)
{
    unordered_map<int, int>mp;
    for(int i=0;i<m;i++)
    {
        mp[ar1[i]]++;
    }
    // set<int>s;
    for(int i=0; i<n;i++)
    {
        
        if(mp.find(ar2[i]) != mp.end() and mp[ar2[i]] > 0)
        {
            cout << ar2[i] << " ";
        }
        mp[ar1[i]]--;
        // s.insert(ar2[i]);
    }

}
int main()
{
    int ar1[] = {1,1,2,2,2,3,5};
    int ar2[] = {1,1,1,2,2,4,5};
    int m=sizeof(ar1) / sizeof(int);
    int n=sizeof(ar2) / sizeof(int);
    commonelement2(ar1,m,ar2,n);
    return 0;
}