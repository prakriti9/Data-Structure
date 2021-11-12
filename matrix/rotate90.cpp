#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int mat[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    // Transpose matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i!=j)
            {
                swap(mat[i][j] , mat[j][i]);
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j >= 0; j--)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}