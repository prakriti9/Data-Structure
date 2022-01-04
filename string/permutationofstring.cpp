#include <iostream>
#include <string>
using namespace std;

void permuttation(string s, int l, int r)
{
    if(l == r)
    cout << s <<endl;
    else
    {
        for(int i=0;i<=r;i++)
        {
            swap(s[l], s[i]);
            permuttation(s, l+1, r);
            swap(s[l], s[i]);
        }
    }
}
int main()
{
    string s = "abcd";
    permuttation(s, 0, s.length()-1);
    return 0;
}