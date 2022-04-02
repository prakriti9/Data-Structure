#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

char highestfreq(string str)
{
    unordered_map<char, int> mp;
    for(int i=0; i<str.length(); i++)
    {
        mp[str[i]]++;
    }
    char ans, val=0;
    for(auto x: mp)
    {
        if(val < x.second)
        {
            ans = x.first;
            val = x.second;
        }
    }
    return ans;
}
int main()
{
    string str="abcaaacghihefahcebb";
    cout << highestfreq(str);
    return 0;
}