#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string removeduplicate(string str)
{
    unordered_map<char, int> mp;
    string ans ="";
    for(int i=0; i<str.length(); i++)
    {
        if(mp.find(str[i]) == mp.end())
        {
            ans += str[i];
        }
        mp[str[i]] += 1;
    }
    return ans;
}
int main()
{
    string str = "geeksforgeeks";
    cout << removeduplicate(str) << endl;
    return 0;
}