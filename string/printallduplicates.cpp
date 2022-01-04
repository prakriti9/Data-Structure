#include <bits/stdc++.h>
using namespace std;

void duplicates(string s)
{
    map <char, int> mp;
    for(int i=0;i<s.length();i++)
    {
        mp[s[i]]++;
    }
    for(auto x: mp)
    {
        if(x.second > 1)
            cout <<x.first <<", count = " << x.second <<endl;
    }
}

int main()
{
    string s = "test string";
    duplicates(s);
    return 0;
}