#include<iostream>
#include<vector>
#include<Algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int best = nums[0]+nums[1]+nums[2];
        for(int i = 0 ; i<n ; i++)
        {
           if(i>0 && nums[i]==nums[i-1]) continue;
           int j = i+1;
           int k = n-1;
           while(j<k)
           {
            int sum = nums[i]+nums[j]+nums[k];
            if(abs(target-sum)<abs(target-best)) best = sum;
            if(sum==target) return sum;
            else if(sum<target)j++;
            else k--;
           }
        }
        return best;
    }
};
int main()
{
    vector<int> nums = {1,3,2,1,4,3,6,-1,0,2};
    int target = 19;
    Solution obj;
    cout<<"closest sum: "<<obj.threeSumClosest(nums,target);
    return 0;
}