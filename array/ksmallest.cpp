#include <bits/stdc++.h>
using namespace std;
int ksmallest(int ar[], int n, int k)
{
    priority_queue <int> q;
    for(int i=0;i<n;i++)
    {
        q.push(ar[i]);
        if(q.size() > k)
        {
            q.pop();
        }
    }
    return q.top();
}
int main()
{
    int ar[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(ar)/sizeof(int);
    cout << ksmallest(ar, n, 3);
    return 0;
}