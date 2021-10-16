#include<iostream>
#include<string>
using namespace std;

string title(string s)
{
    if(s[0] >= 'a' and s[0]<= 'z')
        s[0] -= 32;

    for(int i=1; i<s.length() - 1; i++)
    {
        if(s[i] == ' ')
        {
            if(s[i+1] >= 'a' and s[i+1]<= 'z')
                s[i+1] -= 32;
        
        }
    }
    return s;
}
int main()
{
    string str = "i love programming";
    string s = title(str);
    cout << s <<" ";
    return 0;
}