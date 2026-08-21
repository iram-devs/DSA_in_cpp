#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end()); //sorting array
        nums.erase(unique(nums.begin(),nums.end()),nums.end()); //remove duplicates
        int n = nums.size(); //calculate n after removing duplicates
        if(n<3) return nums[n-1]; //returning largest element
        return nums[n-3]; //returning third larget element
    }
};
int main()
{
    vector<int> nums = {2,2,3,1,4,4,5,9};
    Solution obj;
    int ans = obj.thirdMax(nums);
    cout<<ans<<endl;
    return 0;
}
