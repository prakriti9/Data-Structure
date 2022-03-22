#include <iostream>
#include <vector>
// #include <sstream>
#include <cstring>
using namespace std;

vector <string> tokentization(string s)
{
    vector <string> v;
    int j = 0;
    for(int i=0; i<s.length();i++)
    {
        string str = "";
        if(s[i] == ' ')
        {
            while(j<i)
            {
                str += s[j];
                j++;
            }
            v.push_back(str);
            j = i+1;
        }
    }
    string str = "";
    while(j<s.length())
    {
        str += s[j++];
    }
    v.push_back(str);
    return v;
}
// vector <string> tokentization(string str)
// {
//     vector <string> v;
//     stringstream ss(str);
//     string s;
//     while(getline(ss, s, ' '))
//     {
//         v.push_back(s);
//     }
//     return v;
// }

int main()
{
    char str[1000] = "I love Niall Horan";
    vector <string> v = tokentization(str);
    for(auto x: v)
    {
        cout << '"' << x << '"' << endl;
    }
    return 0;
}