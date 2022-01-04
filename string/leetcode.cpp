#include <iostream>
#include <string>
using namespace std;
bool checkString(string s) {
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == 'b' and s[i+1] == 'a')
            {
                return false;
            }
        }
        return true;
    }
int main()
{
    string str = "ab";
    cout << checkString(str);
    return 0;
}