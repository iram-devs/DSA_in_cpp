#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = 2*n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i%n])
            {
                st.pop();
            }
            if(i<n)
            {
                ans[i]=(st.empty()) ?-1 :st.top();
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {2,4,1,5,8,6};
    Solution obj;
    vector<int>ans=obj.nextGreaterElements(nums);
    cout<<"resultant array:"<<endl;
    for(int x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}