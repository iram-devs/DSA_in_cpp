#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>maxi)
            {
                maxi=sum;
            }
            if(sum<0)
            {
                sum=0;
            }
        }
        return maxi;
        
    }
};
int main()
{
    vector<int> nums;
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter array elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    Solution obj;
    int ans = obj.maxSubArray(nums);
    cout<<"MaximumSubarray: "<<ans<<endl;
    return 0;

}