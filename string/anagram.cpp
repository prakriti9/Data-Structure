#include <iostream>
#include <algorithm>
#include <string>
// #include <unordered_map>
using namespace std;

bool anagram(string str1, string str2)
{
    // unordered_map <char, int> mp1;
    // for(int i=0; i< str1.length();i++)
    // {
    //     mp1[str1[i]]++;    
    // }
    // unordered_map <char, int> mp2;
    // for(int i=0; i< str2.length();i++)
    // {
    //     mp1[str2[i]]++;    
    // }
    // for(auto x: mp2)
    // {
    //     for(auto y: mp1)
    //     {
    //         if(x != y)
    //         {
    //             return false;
    //         }
    //     }
    // }
    // return true;
    sort(str1.begin(), str1.end());
    sort(str1.begin(), str1.end());
    
    // if
    return (str1 == str2);
    
}
int main()
{
    string st1 = "THING";
    string st2 = "GHINTS";
    cout << anagram(st1, st2);
    return 0;
}