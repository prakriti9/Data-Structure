#include <bits/stdc++.h>
using namespace std;

void insertatbottom(stack <int> s, int x)
{
    if(s.size() == 0)
    s.push(n);
    else
    {   
        char a = s.top();
        s.pop();
        insertatbottom(x);
        s.push(a);
    }
}
void reverse(stack <int> &s)
{
    if(!s.empty())
    {
        auto x = s.top();
        s.pop();
        reverse(s);
        insertatbottom(s, x);
    }
}
int main()
{
   stack <int> s;
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);
   s.push(5);

   while(!s.empty())
   {
       int val = s.top();
       cout << val << " ";
       s.pop();
   }
   return 0;
} // namespace std;
