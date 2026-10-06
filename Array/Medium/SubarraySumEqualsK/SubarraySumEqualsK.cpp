#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int prefixSum =0 ;
        mp[prefixSum]=1;
        int cnt=0;
        for(int i = 0 ;i<nums.size();i++)
        {
            prefixSum+=nums[i];
            cnt+=mp[prefixSum-k];
            mp[prefixSum]++;
        }
        return cnt;
    }
};
int main()
{
    vector<int> nums = {2,1,3,4,0,-2,3};
    int k= 4;
    Solution obj;
    cout<<"Total subarray: "<<obj.subarraySum(nums,k);
    return 0;
}