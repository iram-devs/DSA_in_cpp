#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int maxi=INT_MIN;
       int prefix=1;
       int suffix =1;
       for(int i=0;i<nums.size();i++)
       {
         prefix*=nums[i];
         suffix*=nums[nums.size()-i-1];
         if(prefix==0) prefix=1;
         if(suffix==0) suffix=1;
         maxi = max(maxi,max(suffix,prefix));
       }
        return maxi;
    }
};
int main()
{
    vector<int>nums={2,3,-2,4};
    Solution obj;
    int ans = obj.maxProduct(nums);
    cout<<ans<<endl;
    return 0;
}