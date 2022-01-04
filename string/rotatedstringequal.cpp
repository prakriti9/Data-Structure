#include <iostream>
#include <string>
using namespace std;

bool rotatedstring(string str1, string str2)
{
    string str = str1 + str2;
    if(str1.length() != str2.length())
        return false;

    if(str.find(str2) != string::npos)
        return false;
    return true;
}
int main()
{
    string str1 = "louistomlinson";
    string str2 = "tomlinsonlouis";

    if(rotatedstring(str1, str2))
    {
        cout << "Its rotated string";
    }
    else
    {
        cout << "Not the same";
    }
    return 0;
}