#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isincreasing(vector<int> nums)
    {
        for(int i =1 ;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1]) return false;
        }
        return true;
    }
    bool isdecreasing(vector<int> nums)
    {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1]) return false;
        }
        return true;
    }
    bool isMonotonic(vector<int>& nums) {
        return (isincreasing(nums)||isdecreasing(nums));
    }
};
int main()
{
    vector<int> v1 = {1,2,2,3,4};
    vector<int> v2 ={1,3,2,5};
    Solution obj1 , obj2 ;
    bool ans1 = obj1.isMonotonic(v1);
    bool ans2 = obj2.isMonotonic(v2);
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    return 0;
}