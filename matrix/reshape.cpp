#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> reshape(vector<vector<int>> &v, int r, int c)
{
    // int row = v.size();
    // int col = v[0].size();
    // if(row * col != r*c) return v;

    // vector<vector<int>> ans(r, vector <int> (c));
    // int rows = 0, cols = 0;
    // for(int i=0;i < row;i++)
    // {
    //     for(int j=0;j<col;j++)
    //     {
    //         ans[rows][cols] = v[i][j];
    //         cols++;
    //         if(cols == c)
    //         {
    //             cols = 0;
    //             rows++;
    //         }
    //     }

    // }
    // return ans;

    int rows = v.size();
        int col = v[0].size();
        if((r*c) != (rows* col)) return v;
        
        vector <vector<int>> output (r, vector <int> (c));
        int row = 0;
        int colm = 0;
        for(int i = 0;i < rows; i++)
        {
            for(int j = 0; j <col; j++)
            {
                output[row][colm] = v[i][j];
                colm++;
                if(colm == c)
                {
                    colm = 0;
                    row++;
                }
            }
            
        }
        return output;
}

int main()
{
    int n,m;
    cin >>n >>m;
    vector<vector<int>> v;
    // int mat[n][m];
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
    int r, c;
    cin >> r >> c;
    vector<vector<int>> res = reshape(v, r, c);
    for(int i=0;i<v.size();i++)
    {
        for(int j =0;j<v[0].size();j++)
        {
            cout <<res[i][j] <<" ";
        }
        cout << endl;
    }
    return 0;
}