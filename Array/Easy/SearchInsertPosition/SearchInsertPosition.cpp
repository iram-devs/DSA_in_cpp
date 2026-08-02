#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if (n==0) return 0;
        for(int i=0;i<n;i++)
        {
            if (nums[i]==target) return i;
            if (nums[i]>target) return i;
        }
        return n;
        
    }
};
int main()
{
    vector <int> nums = {2,5,6,8,9};
    int target = 7;
    Solution obj;
    int ans = obj.searchInsert(nums , target);
    cout<<ans<<endl;
    return 0;
}