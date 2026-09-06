#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0 , high = nums.size()-1;
        while(low<high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] > nums[high]) low = mid+1;
            else if (nums[mid]<nums[high]) high = mid;
            else high--;
        }
        return nums[low];
    }
};
int main()
{
    vector<int> nums = {4,5,0,1,2,3};

    Solution obj;
    int ans = obj.findMin(nums);
    cout<<ans<<endl;
    return 0;
}