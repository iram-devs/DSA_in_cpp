#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int lowerBound(vector<int> v , int target)
    {
        int low =0 , high = v.size()-1;
        int ans = v.size();
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(v[mid] >= target)
            {
                ans= mid;
                high = mid -1;
            }
            else 
            {
                low = mid + 1;
            }
        }
        return ans ;
    }
    int upperBound(vector <int> v , int target)
    {
        int ans = v.size();
        int low = 0 , high = v.size()-1;
        while (low <= high)
        {
            int mid = low + (high-low)/2;
            if(v[mid]> target)
            {
                ans = mid ;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans ;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans;
        int lb = lowerBound(nums , target);
        int ub = upperBound(nums , target);
        if(lb == nums.size() || nums[lb]!=target)
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(lb);
            ans.push_back(ub-1);
        }
        return ans;
    }
};
int main()
{
    vector<int> nums={1,3,4,4,4,5,6,6,7};
    Solution obj;
    vector<int>ans= obj.searchRange(nums,4);
    for(int x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}