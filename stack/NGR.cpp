#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
// nearest greatest right
vector <int> NGR(int ar[], int n)
{
    vector <int> v;
    stack <int> s;
    for(int i=n-1; i>=0;i--)
    {
        if(s.size() == 0)
            v.push_back(-1);
        else if(s.size() > 0 and ar[i] < s.top())
        {
            v.push_back(s.top());
        }
        else if(s.size() > 0 and ar[i] >= s.top())
        {
            while(s.size() > 0 and ar[i] >= s.top())
            {
                s.pop();
            }
            if(s.size() == 0)
            {
                v.push_back(-1);
            }
            else v.push_back(s.top());
        }
        s.push(ar[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

// nearest greatest left

vector <int> NGL(int ar[], int n)
{
    vector <int> v;
    stack <int> s;
    for(int i=0; i<n;i++)
    {
        if(s.empty())
            v.push_back(-1);
        else if(s.size() > 0 and ar[i] < s.top())
        {
            v.push_back(s.top());
        }
        else if(s.size() > 0 and ar[i] >= s.top())
        {
            while(s.size() > 0 and ar[i] >= s.top())
            {
                s.pop();
            }
            if(s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }
        s.push(ar[i]);
    }
    return v;
}
// smallest number from right

vector <int> NSR(int ar[], int n)
{
    vector <int> v;
    stack <int> s;
    for(int i=n-1; i>=0; i--)
    {
        if(s.empty())
            v.push_back(-1);
        else if(s.size() > 0 and ar[i] > s.top())
        {
            v.push_back(s.top());
        }
        else if(s.size() > 0 and ar[i] <= s.top())
        {
            while(s.size() > 0 and ar[i] <= s.top())
            {
                s.pop();
            }
            if(s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }
        s.push(ar[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}
vector <int> NSL(int ar[], int n)
{
    vector <int> v;
    stack <int> s;
    for(int i=0; i<n;i++)
    {
        if(s.size() == 0)
            v.push_back(-1);
        else if(s.size() > 0 and ar[i] > s.top())
        {
            v.push_back(s.top());
        }
        else if(s.size() > 0 and ar[i] <= s.top())
        {
            while(s.size() > 0 and ar[i] <= s.top())
            {
                s.pop();
            }
            if(s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }
        s.push(ar[i]);
    }
    return v;
}
int main()
{
    int ar[] = {4, 5, 2, 1, 0, 8};
    int n = sizeof(ar) / sizeof(int);
    vector <int> v = NSL(ar, n);
    for(auto a: v)
    {
        cout << a << " ";
    }
    return 0;
}