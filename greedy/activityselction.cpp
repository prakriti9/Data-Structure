// count no. of maximum activities that can be performed
#include <bits/stdc++.h>
using namespace std;
int maxactivity(int start[], int finish[], int n)
{
    int val = 1;
    vector <pair<int , int>> v;
    for(int i=0; i<n;i++)
    {
        v.push_back({finish[i], start[i]});
    }
    sort(v.begin(), v.end());
    int prev = 0;
    // for(int curr =1; curr<n;curr++)
    // {
    //     if(v[curr].second > v[prev].first)
    //     {
    //         val++;
    //         prev = curr;
    //     }
    // }
    for(int curr =1; curr<n;curr++)
    {
        if(finish[curr] > start[prev])
        {
            val++;
            prev = curr;
        }
    }

    // when you wanna check if you have made a vector of pair or not
    // for(int i=0;i <n;i++)
    // {
    //     cout << v[i].first <<" " << v[i].second;
    //     cout <<endl;
    // }

    return val;
}
int main()
{
    int start[]  =  {1, 3, 2, 5};
    int finish[] =  {2, 4, 3, 6};
    int n = *(&start + 1) - start;
    cout << maxactivity(start, finish, n);
    return 0;
}