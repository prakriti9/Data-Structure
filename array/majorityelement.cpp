#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums) {
        
        int ele = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt == 0)
                ele = nums[i];
            if(ele == nums[i])
                cnt++;
            else
                cnt--;
        }
        return ele;
}
int main()
{
    vector<int> nums= {1,2,5,5,5,6,6,5,5};
    cout << majorityElement(nums);
    return 0;
}