#include <iostream>
#include <string>
using namespace std;

string space20(string str)
{
    string s = "";
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == ' ')
        {
            s += "%20";
        }
        else
        {
            s += str[i];
        }
    }
    return s;
}
int main()
{
    string str = "Hello Niall Horan. Nice to meet ya!!";
    string s = space20(str);
    cout << s << endl;
    return 0;
}