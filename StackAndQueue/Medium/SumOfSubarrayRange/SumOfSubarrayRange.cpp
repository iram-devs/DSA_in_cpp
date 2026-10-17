#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> nextSmaller(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>ans(n);
        stack<int> st;
        for(int i=n-1 ; i>=0 ;i--)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            ans[i]=(st.empty())?n :st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerOrEqual(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>ans(n);
        stack<int> st;
        for(int i=0 ; i<n ;i++)
        {
            while(!st.empty() && nums[st.top()]>nums[i])
            {
                st.pop();
            }
            ans[i]=(st.empty())?-1 :st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextGreater(vector<int>&nums)
    {
        int n = nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i = n-1 ;i>=0 ;i--)
        {
            while(!st.empty() && nums[st.top()]<=nums[i])
            {
                st.pop();
            }
            ans[i]=(st.empty()) ?n :st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevGreaterOrEqual(vector<int>&nums)
    {
        int n = nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0 ; i<n ; i++)
        {
            while(!st.empty()&&nums[st.top()]<nums[i])
            {
                st.pop();
            }
            ans[i]=(st.empty())?-1 :st.top();
            st.push(i);
        }
        return ans;
    }
   long long miniSum(vector<int>&nums)
    {
        int n = nums.size();
        vector<int> nse = nextSmaller(nums);
        vector<int>psee = prevSmallerOrEqual(nums);
        long long total = 0;
        for(int i = 0; i<n ; i++)
        {
            int left = i - psee[i];
            int right = nse[i]-i;
            total = (total + 1LL*left*right*nums[i]);
        }
        return total;

    }
    long long maxiSum(vector<int>&nums)
    {
        int n =nums.size();
        vector<int> nge = nextGreater(nums);
        vector<int>pgee = prevGreaterOrEqual(nums);
        long long total = 0;
        for(int i = 0; i<n ;i++)
        {
            int left = i - pgee[i];
            int right = nge[i]-i;
            total = (total+ 1LL* left*right*nums[i]);
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        return maxiSum(nums)-miniSum(nums);
    }
};
int main()
{
    vector<int> nums = {4,2,1,3};
    Solution obj;
    cout<<"Ans: "<<obj.subArrayRanges(nums);
    return 0;
}