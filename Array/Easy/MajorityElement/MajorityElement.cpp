#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         int n=nums.size();
         return nums[n/2];
    }
};
int main()
{
    vector<int>nums = {1,2,2,1,1,2,1};
    Solution obj;
    int ans = obj.majorityElement(nums);
    cout<<ans<<endl;
    return 0;
}