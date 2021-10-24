#include <iostream>
using namespace std;

void pattern(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(i==j || (i+j) == n-1)
            cout << "*\t";
            else
            {
                cout << "\t";
            }

        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    pattern(n);
    return 0;
} 
