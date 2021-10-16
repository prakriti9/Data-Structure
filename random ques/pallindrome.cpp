// to find the pallindrome
#include <bits/stdc++.h>
using namespace std;

bool pallindrome(int n)
{
    string str = to_string(n);
    int i=0;
    int j= str.length() - 1;
    while(i<=j)
    {
        if(str[i] != str[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    
    if(pallindrome(n))
    {
        cout << "PALLINDROME";
    }
    else
    {
        cout << "NOT PALLINDROME";
    }
    return 0;
}