#include <bits/stdc++.h>
using namespace std;

bool formed(string str)
{
    stack <char> s;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == '[' || str[i] == '{' || str[i] == '(')
        {
            s.push(str[i]);
        }
        if(s.empty())
            return false;
        else
        {
            auto tp = s.top();
            if(str[i] == ']' and tp == '[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            if(str[i] == '}' and tp == '{')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            if(str[i] == ')' and tp == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        
        }
    }
    if(s.empty())
        return true;
    return false; 
}
int main()
{
    string str = "{[()]}";
    cout << formed(str);
    return 0;
}