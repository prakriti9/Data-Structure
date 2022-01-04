#include <bits/stdc++.h>
using namespace std;

string rev(string s)
{
    int i=0 , j = s.length() - 1;
    int count = 1;
    string str ="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == 'a' || s[i] == 'i'|| s[i] == 'u' || s[i] == 'o' || s[i] == 'e')
        {
            str += to_string(count);
            count++;
        }
        else
        {
            str += s[i];
        }
    }
    
    while(i <=j)
    {
        swap(str[i++], str[j--]);
    }

    return str;
}
int main()
{
   string s = "Language";
    string str = rev(s);
    cout << str <<endl;
   return 0; 
} 