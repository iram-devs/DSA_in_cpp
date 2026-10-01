#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int atMost(vector<int>&nums , int k)
    {
        if(k==0) return 0;
        map<int,int>mp;
        int left = 0;
        int ans = 0;
        for(int right = 0 ;right<nums.size();right++)
        {
            mp[nums[right]]++;
            while(mp.size()>k)
            {
                mp[nums[left]]--;
                if(mp[nums[left]]==0) 
                {
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1) ;
    }
};
int main()
{
    vector<int> nums(7);
    cout<<"Enter array elements: "<<endl;
    for(int i=0;i<7;i++)
    {
        int x ;
        cin>>x;
        nums.push_back(x);
    }
    int k;
    cout<<"Enter K: ";
    cin>>k;
    Solution obj;
    cout<<"Subarrays with "<<k<<" different integers are : "<<obj.subarraysWithKDistinct(nums,k);
    return 0;
}