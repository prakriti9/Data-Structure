#include<bits/stdc++.h>
using namespace std;

void reverse(string s)
{
    int i=0, j = s.length() - 1;
    while(i<=j)
    {
        swap(s[i++], s[j--]);
    }
    // return s;
}
string adddot(int n)
{
    string str;
    int count = 0;
    if(n == 0)
    {
        return "0";
    }
    if(n < 999)
    {
        return to_string(n);
    }
    while(n!=0)
    {
        int rem = n%10;
        if(count < 3)
        {
            str += to_string(rem);    
        }
        else
        {
            str += to_string(rem);  
            str += '.';
            count=0;
        }
        count++;
        n= n/10;
    }
    reverse(str.begin(), str.end());
    return str;
}
int main()
{
    int n = 123456789;
    cout <<endl;
    cout << adddot(n) << ' ';
    return 0;
}