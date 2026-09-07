#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxMoney(int idx , int n , vector<int>&nums , vector<int> &dp)
    {
        if(idx>=n) return 0;
        if(idx == n-1) return nums[idx];
        if(dp[idx] != -1) return dp[idx];

        int rob = nums[idx] + maxMoney(idx+2 , n , nums , dp);
        int not_rob = maxMoney(idx+1 , n, nums , dp);
        return dp[idx]=max(rob,not_rob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> dp(n , -1);
        return maxMoney(i , n , nums , dp);
        
    }
};
int main()
{
    vector<int> nums = {1,2,3,1};
    Solution obj;
    int ans = obj.rob(nums);
    cout<<ans<<endl;
    return 0;
}