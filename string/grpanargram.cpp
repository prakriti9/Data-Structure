#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


vector <vector <string>> anagram(vector <string> arr)
{
    vector <vector <string>> ans;
    unordered_map<string, vector<string>> mp;
    string temp;
    for(int i=0; i<arr.size(); i++)
    {
        temp = arr[i];
        sort(arr[i].begin(), arr[i].end());
        mp[arr[i]].push_back(temp);
    }
    for(auto x: mp)
    {
        ans.push_back(x.second);
    }
    return ans;
}
int main()
{
    vector <string> arr = {"eat", "ate", "tea", "tan", "ant","bat"};
    vector <vector <string>> ans = anagram(arr);
    for(auto x: ans)
    {
        for(auto it: x)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}