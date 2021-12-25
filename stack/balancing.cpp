#include <bits/stdc++.h>
using namespace std;

bool balance(string str)
{
    stack <char> s;
    for(auto x: str)
    {
        switch(x)
        {
            case '(': 
            case '[':
            case '{': s.push(x);
            break;

            case ')': if(!s.empty() and s.top() == '(')
                        {
                            s.pop(); 
                        }
                        else
                            return false;
            break;
            case ']': if(!s.empty() and s.top() == '[')
                        {
                            s.pop(); 
                        }
                        else
                            return false;
            break;
            case '}': if(!s.empty() and s.top() == '{')
                        {
                            s.pop(); 
                        }
                        else
                            return false;
            break;

            default: continue;
        }
    }
    if(!s.empty())
    {
        return false;
    }
    return true;
}
int main()
{
    string str = "[{(a+b) % b} * (d)] + {a}*8";

    if(balance(str))
    {
        cout << "Yes it is balanced!! ";
    }
    else
        cout << "No it is not balanced!! ";
    return 0;
} 
