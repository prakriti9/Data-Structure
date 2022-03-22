#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;


string reverseword(string str)
{
    stack <string> st;
    string temp;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == ' ')   continue;
        temp = "";
        while(i < str.length() and str[i] != ' ')
        {
            temp += str[i];
            i++;
        }
        st.push(temp);
    }
    string ans = "";
    while(!st.empty())
    {
        if(st.size() > 1)
        {
            ans += st.top();
            ans += " ";
            st.pop();
        }
        else
        {
            ans += st.top();
            st.pop();
        }
    }
    return ans;
}
int main()
{
    string str = "the sky is blue";
    cout << reverseword(str);
    return 0;
}