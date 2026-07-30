#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int replace=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]!=nums[i])
            {
                nums[replace]=nums[i];
                replace++;
            }
        }
        return replace;
        
    }
};
int main()
{
    vector<int> nums = {1,1,2,3,3,3,4,4,5,5};
    Solution obj;
    int ans = obj.removeDuplicates(nums);
    cout<< ans<<endl;
    return 0;

}