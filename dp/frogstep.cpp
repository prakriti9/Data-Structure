#include <bits/stdc++.h>
using namespace std;

int minstep(int idx, vector <int> v)
{
    if(idx==0)
        return 0;
    
    int left = minstep(idx-1, v) + abs(v[idx] - v[idx-1]);
    int right;
    if(idx>1)
        int right = minstep(idx-2, v) + abs(v[idx] - v[idx-2]);
    return min(left , right);
}

int main()
{
    vector <int> v = {10, 20, 30, 10};
    cout << minstep(v.size() - 1, v);
    return 0;
}