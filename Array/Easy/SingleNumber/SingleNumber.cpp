#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int value:nums)
        {
            ans^=value;
        }
        return ans;
        
    }
};
int main()
{
    vector<int> nums = {1,2,2,3,1};
    Solution obj;
    int ans = obj.singleNumber(nums);
    cout<<ans<<endl;
    return 0;
}