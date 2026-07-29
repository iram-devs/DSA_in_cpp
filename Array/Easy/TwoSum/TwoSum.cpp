#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int left=0 , right=v.size()-1;
        while(left<right)
        {
            int sum=v[left].first+v[right].first;
            if(sum==target)
            {
                return{v[left].second,v[right].second};
            }
            else if(sum<target)left++;
            else right--;
            }
            return{};
    }
};
int main()
{
    vector<int> nums ={3,2,4};
    int target = 6;
    Solution obj;
    vector<int> ans = obj.twoSum(nums , target);
    for(int a: ans)
    {
        cout<<a<<" ";
    }
    return 0;
}