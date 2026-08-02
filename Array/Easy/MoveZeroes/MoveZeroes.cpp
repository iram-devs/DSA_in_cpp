#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
        }
    }
};
int main()
{
    vector<int> nums = {0,1,2,0,3,1};
    Solution obj ;
    obj.moveZeroes(nums);
    for(int x :nums)
    {
        cout<<x<<" ";
    }
    return 0;
}