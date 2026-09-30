#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        int left = 1;
        for(int i=0;i<nums.size();i++)
        {
            ans[i]=left;
            left*=nums[i];
        }
        int right=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans[i]*=right;
            right *= nums[i];
        }
        return ans;
    }
};
int main()
{
    vector<int>v(5);;
    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<5;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    Solution obj;
    vector<int> ans = obj.productExceptSelf(v);
    cout<<"Output:"<<endl;
    for(int y:ans)
    {
        cout<<y<<" ";
    }
    return 0;
}