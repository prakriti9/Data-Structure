#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n+1;i++)
    {
     int val = 10;
        for(int j =0;j<i;j++)
        {
            cout<< val <<".";
            val -= 2;
        }
        cout<< endl;
    }
    return 0;
}