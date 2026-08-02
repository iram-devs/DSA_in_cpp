#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int sum(vector<int> nums, int start , int end)
    {
        int sum = 0;
        for(int i = start ; i<=end;i++)
        {
            sum += nums[i];
        }
        return sum;
    }
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans = {};
        for(int i =0 ;i <nums.size();i++)
        {
            ans.push_back(sum(nums , 0 , i));
        }
        return ans;
        
    }
};
int main()
{
    vector<int> nums = {1,3,4,2,5};
    Solution obj;
    vector<int> ans = obj.runningSum(nums);
    for(int x:ans)

    {
        cout<<x<<" ";
    }
    return 0;
}