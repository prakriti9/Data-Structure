#include <iostream>
#include <vector>
using namespace std;

vector <vector<int>> pascaL (int row)
{
    vector<vector<int>> ans;
        
    for(int i=0; i<row ;i++)
    {
        vector <int> v (i+1 ,1);
        
        for(int j =1;j < i ;j++)
        {
            v[j] = ans[i-1][j] + ans[i-1][j-1];
        }
        ans.push_back(v);
    }
    return ans;
}
int main()
{
    int row;
    cin >> row;

    vector <vector<int>> v = pascaL(row);

    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            cout << v[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}