#include <iostream>
using namespace std;
int main()
{
    int n1,m1;
    cin >>n1 >>m1;
    int mat[n1][m1];
    for(int i=0;i <n1;i++)
    {
        for(int j =0;j<m1;j++)
        {
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<n1;i++)
    {
        for(int j =0;j<m1;j++)
        {
            cout <<mat[i][j] <<" ";
        }
        cout << endl;
    }

    int n2,m2;
    cin >>n2 >>m2;
    int mat[n2][m2];
    for(int i=0;i <n2;i++)
    {
        for(int j =0;j<m2;j++)
        {
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<n2;i++)
    {
        for(int j =0;j<m2;j++)
        {
            cout <<mat[i][j] <<" ";
        }
        cout << endl;
    }
    
    return 0;
}