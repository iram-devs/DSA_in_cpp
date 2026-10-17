#include<iostream>
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector <int> ans;
        deque <int> d;
        for (int i=0;i<nums.size();i++)
        {
            if(!d.empty()&& d.front() <= i-k)
            {
               d.pop_front();
            }
            while(!d.empty() && nums[d.back()] <= nums[i])
            {
                d.pop_back();
            }
            d.push_back(i);
            if(i >= k-1)
            {
                ans.push_back(nums[d.front()]);
            }
        }
         return ans;
         
    }
};
int main()
{
    vector<int>nums = {1,3,2,5,-1,3,-5,2,3,7,1};
    int k = 3;
    Solution obj;
    vector<int>ans=obj.maxSlidingWindow(nums,k);
    cout<<"output:"<<endl;
    for(int x:ans)
    {
        cout<<x<<" ";
    }
    return 0;

}