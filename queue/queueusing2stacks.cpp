#include <bits/stdc++.h>
using namespace std;

class squeue{
    stack <int> s1;
    stack <int> s2;

    public:
    void push(int x)
    {
        s1.push(x);
    }
    int pop()
    {
        int ans;
        if(!s2.empty())
        {
            ans = s2.top();
            s2.pop();
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            if(!s2.empty())
            {
                ans = s2.top();
                s2.pop();
            }
            else
            {
                ans = -1;
            }
        }
        return ans;
    }
};
int main()
{
    squeue sq;
    sq.push(1);
    sq.push(2);
    sq.push(3);
    sq.push(4);
    sq.push(5);
    
    return 0;
}