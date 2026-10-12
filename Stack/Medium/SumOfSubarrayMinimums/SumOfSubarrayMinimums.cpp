#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int>nextSmallerElement(vector<int>&nums)
    {
        int n = nums.size();
        vector<int>ans(n);
        stack<int> st; //to store indexes
        for(int i = n-1 ; i>=0 ;i--)
        {
            while(!st.empty() && nums[st.top()]>= nums[i])
            {
                st.pop();
            }
            ans[i] = (st.empty()) ?n :st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerOrEqualElement(vector<int>&nums)
    {
        int n = nums.size();
        vector<int>ans(n);
        stack<int>st; //for storing indexes 
        for(int i=0 ;i<n ; i++)
        {
            while(!st.empty() && nums[st.top()]>nums[i])
            {
                st.pop();
            }
            ans[i]=(st.empty()) ?-1 :st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = nextSmallerElement(arr);
        vector<int>psee = prevSmallerOrEqualElement(arr);
        int total = 0 ;
        int mod = (int)(1e9 + 7);
        for(int i = 0; i<arr.size(); i++)
        {
            int left = i - psee[i];
            int right = nse[i]-i;
            total = (total + 1LL * right*left *arr[i])%mod;
        }
        return total;
    }
};
int main()
{
    vector<int> nums = {3,1,4,2};
    Solution obj;
    cout<<"ans: "<<obj.sumSubarrayMins(nums);
    return 0;
}