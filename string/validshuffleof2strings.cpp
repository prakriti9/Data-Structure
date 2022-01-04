#include <bits/stdc++.h>
using namespace std;

bool validshuffle(string str1, string str2, string res)
{
    if((str1.length() + str2.length()) != res.length())
        return false;
    else
    {
        int i = 0, j = 0, k = 0;
        while(k < res.length())
        {
            if(i < str1.length() and str1[i] == res[k])
                i++;
            else if(j < str2.length() and str2[j] == res[k])
                j++;
            else
            {
                return false;
            }
            k++;
        }
        if(i < str1.length() or j < str2.length())
            return false;
    }
    return true;
}
int main()
{
    string str1 = "XY";
    string str2 = "12";
    string res = "Y1X2";
    if(validshuffle(str1, str2, res))
    {
        cout << "Valid Shuffle";
    }
    else
        cout << "Invalid";
    return 0;
}