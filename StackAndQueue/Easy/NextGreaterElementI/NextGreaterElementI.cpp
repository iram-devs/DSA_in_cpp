#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution{
    public:
    vector<int> nextGreaterElement(vector<int>&nums)
    {
        int n = nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i = n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i])
            {
                st.pop();
            }
            ans[i]=(st.empty()) ?-1 :st.top();
            st.push(nums[i]);
        }
        return ans;
    } 
};
int main()
{
    vector<int> nums={2,1,3,5,2,8};
    Solution obj;
    vector<int>ans=obj.nextGreaterElement(nums);
    cout<<"resultant array:"<<endl;
    for(int x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}