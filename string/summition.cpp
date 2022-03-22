#include <bits/stdc++.h>

using namespace std;

long long summition(string str)
{
    long long int sum = 0;
    int val = 0;
    string temp = "";
    for(int i=0; i<str.length();i++)
    {
        if(str[i] == ', ')
        {
            sum += stoi(temp);
            temp = "";
        }
        temp += str[i];
    }
    sum += stoi(temp);
    return sum;
}
int main()
{
    string str;

    getline(cin, str);
    cout << summition(str) << endl;

    return 0;
}