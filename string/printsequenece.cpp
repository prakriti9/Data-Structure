#include <bits/stdc++.h>
using namespace std;

void sequences(string s, string ans)
{
    if(s.empty())
    {
        cout << ans <<endl;
        return;
    }
    char ch = s[0];
    string r = s.substr(1);

    sequences(r, ans + "");
    sequences(r, ans + ch);
}
int main()
{
    string s = "abcd";
    string a = "";

    sequences(s, a);
    
    return 0;
}