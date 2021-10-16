#include<bits/stdc++.h>
using namespace std;

int middleindex(vector <int> v)
{
    int total = 0;
    int n = v.size();
    for(int i=0; i < n;i++)
    {
        total += v[i];
    }
    int curr = 0;
    for(int i=0;i< n;i++)
    {
        if(curr == total-curr-v[i])
        {
            return i;
        }
        curr += v[i];
    }
    return -1;
}

int main()
{
    vector<int> v  = {2,3,-1,8,4};

    cout << middleindex(v) <<" ";
    return 0;
}