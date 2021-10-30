// Matrix is sorted and last elements pf rows are greater than first element of next row


#include <iostream>
#include <vector>

using namespace std;

bool searchin2D(vector<vector<int>> v, int target)
{
    int n = v.size();
    int m = v[0].size();

    int i =0, j = m-1;
    while(i<n and j>=0)
    {
        if(v[i][j] == target)
            return true;
        
        if(v[i][j] > target)
            j--;
        else
            i++;
    }
    return false;
}
int main()
{
    int n,m;
    cin >>n >>m;
    vector<vector<int>> v;
    
    for(int i=0;i <n;i++)
    {
        vector<int> a;
        for(int j =0;j<m;j++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        v.push_back(a);
    }
    int target;
    cin >> target;
    cout << searchin2D(v, target);
    return 0;
}