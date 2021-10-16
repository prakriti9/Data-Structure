#include <iostream>
#include <string>
using namespace std;

string encryp(string s)
{
    // string s;
    for(int i=0;i<s.length();i++)
    {
        s[i] -= 3;
        if(s[i] <= 'a')
        {
            s[i] += 26;
        }
    }
    return s;
}
string decryp(string s)
{
    for(int i=0;i<s.length();i++)
    {
        s[i] += 3;
        if(s[i] >= 'z')
        {
            s[i] -= 26;
        }
    }
    return s;
}
int main()
{
    string str = "quick";
    cout << encryp(str) << endl;
    string s = encryp(str);
    cout << decryp(s) << endl;
    return 0;
}