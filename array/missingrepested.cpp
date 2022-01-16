#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// vector<int> missingrepated(int *ar, int n)
// {
//     vector <int> v;
//     sort(ar, ar + n);
//     for(int i=1; i<= n;i++)
//     {
//         if(ar[i] == ar[i+1])
//         {
//             v.push_back(ar[i]);
//         }
//     }
//     for(int i=1; i<=n;i++)
//     {
//         if(ar[i] != i)
//         {
//             v.push_back(i);
//             break;
//         }
//     }
//     return v;
// }
vector<int> missingrepated(int *ar, int n)
{
    vector <int> v;
    int ans = 0;
    for(int i =0; i<n;i++)
    {
        ans ^= ar[i];
    }
    for(int i = 1; i<=n;i++)
    {
        ans ^= i;
    }
    int x = 0, y = 0;
    int setval = ans & ~(ans - 1);
    for(int i=0; i<n ; i++)
    {
        if(ar[i] & setval)
            x = x ^ ar[i];
        else
            y = y ^ ar[i];
    }
    for(int i=1; i<= n;i++)
    {
        if(i & setval)
            x = x ^ i;
        else
            y = y ^ i;
    }
    for(int i=0; i<n;i++)
    {
        if(x == ar[i])
        {
            v.push_back(x);
            v.push_back(y);
            return v;
        }
    }
    v.push_back(y);
    v.push_back(x);
    return v;
}
int main()
{
    int ar[] = {1, 3, 3};
    int n = sizeof(ar) /sizeof(int);
    vector<int> a = missingrepated(ar, n);
    cout << a[0] << " " << a[1];
} // namespace std;
