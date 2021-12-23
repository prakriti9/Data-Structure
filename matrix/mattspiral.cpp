#include <bits/stdc++.h> 
using namespace std;
int main()
{
    // vector <vector <int>> v;

    int m, n;
    cin >> m >> n;
    int ar[m][n];
    for(int i=0; i<m;i++)
    {
        for(int j=0; j<n;j++)
        {
            cin >> ar[i][j];
        }
    }

    for(int i=0; i<m;i++)
    {
        for(int j=0; j<n;j++)
        {
            cout << ar[i][j] << " ";
        }
    }

    // print in spiral format
    cout << endl;
    int T = 0, B = m-1, L = 0, R = n-1;
    int dir = 0;
    while(T <= B and L <= R)
    {
        if(dir == 0)
        {
            for(int i=L;i<= R;i++)
            {
                cout << ar[T][i] << " ";
            }

            T++;
            dir += 1;
        }
        if(dir == 1)
        {   
            for(int i = T; i<= B;i++)
            {
                cout << ar[i][R] << " ";
            }
            R--;
            dir += 1;
        }
        if(dir == 2)
        {
            for(int i= R;i >= L;i--)
            {
                cout << ar[B][i] << " ";
            }
            B--;
            dir += 1;
        }
        if(dir == 3)
        {
            for(int i=B;i>= T;i--)
            {
                cout << ar[i][L] << " ";
            }
            L++;
            dir = (1 + dir) % 4;
        }
    }
    return 0;
}