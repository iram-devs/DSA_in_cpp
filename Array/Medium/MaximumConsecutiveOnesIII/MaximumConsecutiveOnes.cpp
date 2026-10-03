#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int ans = INT_MIN;
        int zeroes = 0;
        for(int right = 0 ;right<nums.size();right++)
        {
             if(nums[right]==0) zeroes++;
             while(zeroes>k)
             {
                if(nums[left]==0) zeroes--;
                left++;
             }
             ans = max(ans,right-left+1);
        }
        return ans;
    }
};
int main()
{
    vector<int> nums;
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    cout<<"Enter array elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    int k;
    cout<<"Enter k: ";
    cin>>k;
    Solution obj;
    cout<<"Max ones: "<<obj.longestOnes(nums,k);
    return 0;
}
