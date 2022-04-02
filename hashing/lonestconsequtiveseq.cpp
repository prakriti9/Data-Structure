#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}
int longestconseq(int ar[], int n)
{
    unordered_map <int, bool> mp;
    for(int i=0; i<n;i++)
    {
        mp[ar[i]] = true;
    }
    for(int i=0; i<n;i++)
    {
        if(mp.find((ar[i])-1) != mp.end())
        {
            mp[ar[i]] = false;
        }
    }
    int ans = 0;
    for(int i=0; i <n;i++)
    {
        if(mp[ar[i]] == true)
        {
            int tmp = ar[i];
            int t1 = 1;
            vector <int> v;
            v.push_back(tmp);
            while(mp.find(tmp+t1) != mp.end())
            {
                v.push_back(ar[i]);;
                t1 += 1;
            }
            ans = max(ans, v.size());
        }
    }
    return ans;
}
// int longestconseq(int ar[], int n)
// {
//     set <int> s;
//     for(int i=0; i<n;i++)
//     {
//         s.insert(ar[i]);
//     }
//     int ans = 0;
//     for(int i=0; i<n;i++)
//     {
//         if(!s.count(ar[i] - 1))
//         {
//             int currentnum = ar[i];
//             int cnt = 1;
//             while(s.count(currentnum+1))
//             {
//                 currentnum += 1;
//                 cnt += 1;
//             }
//             ans = max(ans, cnt);
//         }
//     }
//     return ans;
// }
int main()
{
    int ar[] = {10, 5, 9, 1, 11, 8, 6, 15, 3, 12, 2};
    int n = sizeof(ar) / sizeof(int);
    cout << longestconseq(ar, n);

    return 0;
}