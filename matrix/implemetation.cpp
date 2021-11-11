#include <iostream>
using namespace std;

// int uppertriangle(i)
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
    cout << endl;
    // matrix reading column vise
    cout <<"COLUMN WISE\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[j][i] << " ";
        }
        cout << endl;
    }
    // half triangle / lower triangle
    cout <<"LOWER TRANGLE\n";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i >= j)
                cout << mat[i][j] << " ";
            else
            cout <<"0 ";
        }
        cout << endl;
    }

    // upper triangle
    cout << endl;
    cout <<"UPPER TRAINGLE\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i==j or (j>i))
                cout << mat[i][j] << " ";
            else
            cout <<"0 ";
        }
        cout << endl;
    }
    // diagonal only
    cout << endl;
    cout <<"DIAGONALS\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i == j)
                cout << mat[i][j] << " ";
            else
            cout <<"0 ";
        }
        cout << endl;
    }
    return 0;
}