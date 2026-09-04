#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    bool canDivide(vector<int> &nums , int k , int threshold)
    {
        int ans = 0;
        for(int i = 0 ;i<nums.size();i++)
        {
            ans += (nums[i]+k-1)/k;
        }
        if(ans<=threshold) return true;
        else return false;
    }
    int smallestDivisor(vector<int>&nums , int threshold)
    {
        int lo = 1;   //min val of search space
        int hi = *max_element(nums.begin(),nums.end());   //max value of search space
        int ans = -1;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            if(canDivide(nums, mid , threshold))
            {
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {1,2,5,9};
    int threshold = 6;

    Solution obj;
    int ans = obj.smallestDivisor(nums , threshold);
    cout<<ans<<endl;
    return 0;
}