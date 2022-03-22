#include <iostream>
#include <vector>
#include <string>
using namespace std;



string isKeyword(string str)
{
    vector <string> v = {"break", "case", "continue", "default", "defer", "else", "for", "while", "int", "double", "if", "return", "map", "range", "return", "func", "goto"};

    string s;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i] == str)
        {
          
            return "Yes its a keyowrd";
        }
            
    }
    return "No its not a keyowrd";
}

int main()
{
    string str;
    cin >> str;

    cout << isKeyword(str) << endl;

    return 0;
}