#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        return max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
        
    }
};
int main()
{
    vector<int>nums={11,-10,-3,2,3,4};
    Solution obj;
    int ans = obj.maximumProduct(nums);
    cout<<ans<<endl;
    return 0;
}