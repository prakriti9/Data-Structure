#include <bits/stdc++.h>
using namespace std;

// bool rotation(string str, string str2)
// {
//     if(str.length() != str2.length())
//         return false;

//     string s = str + str2;
//     if(s.find(str2) != string::npos)
//     {
//         return true;
//     }
//     return false;
// }

// using queue
bool rotation(string str1, string str2)
{
    if(str1.length() != str2.length())
        return false;

    queue <char> q1;
    for(int i = 0; i < str1.length(); i++)
    {
        q1.push(str1[i]);
    }
    queue <char> q2;
    for(int i = 0; i < str2.length(); i++)
    {
        q2.push(str1[i]);
    }
    int k = q2.size();
    while(k--)
    {
        auto x = q2.front();
        q2.pop();
        q2.push(x);
        if(q2 == q1)
            return true;
    }
    return false;
}
 
int main()
{
    string str1 = "louistomlinson", str2 = "tomlinsonlouis";
    if(rotation(str1, str2))
    {
        cout << "Yes";
    }
    else
        cout << "No";
    return 0;
} 

// # include <bits/stdc++.h>
// using namespace std;

// bool areRotations(string str1, string str2)
// {
//    /* Check if sizes of two strings are same */
//     if (str1.length() != str2.length())
//         return false;

//     string temp = str1 + str1;
//     return (temp.find(str2) != string::npos);
// }

// int main()
// {
//     string str1 = "AACD", str2 = "ACDA";
//     if (areRotations(str1, str2))
//     { 
//         cout << "Strings are rotations of each other";
//     }
//     else
//     {
//         cout << "Strings are not rotations of each other";
//     }
//     return 0;
// }
