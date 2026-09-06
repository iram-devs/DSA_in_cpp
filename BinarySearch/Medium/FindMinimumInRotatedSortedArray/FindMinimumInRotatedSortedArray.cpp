#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0 , high = nums.size()-1;
        int ans = INT_MAX;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if (nums[low]<=nums[mid])
            {
                ans = min (ans , nums[low]);
                low = mid + 1;
            }
            else
            {
                ans = min (ans , nums[mid]);
                high = mid - 1;
            }
        }
        return ans ;
    }
};
int main()
{
    vector<int> nums = {5,6,7,1,2,3,4};

    Solution obj;
    int ans = obj.findMin(nums);
    cout<<ans<<endl;
    return 0;
}