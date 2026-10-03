#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int ans =INT_MAX;
        int sum=0;
        for(int right=0;right<nums.size();right++)
        {
            sum+=nums[right];
            while(sum>=target)
            {
                ans = min(ans , right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        if(ans==INT_MAX) return 0;
        else return ans;
    }
};
int main()
{
    vector<int> nums;
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter array elements: "<<endl;
    for(int i = 0 ;i<n ;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    int target;
    cout<<"Enter target: ";
    cin>>target;
    Solution obj;
    cout<<"Output: "<<obj.minSubArrayLen(target , nums);
    return 0;
}