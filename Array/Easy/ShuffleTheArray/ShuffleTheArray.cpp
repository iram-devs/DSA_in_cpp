#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        for(int i =0 ;i<n;i++)
        {
            int j = n+i;
            ans.push_back(nums[i]);
            if(j<2*n)
            {
                ans.push_back(nums[j]);
            }
        }
        return ans;
   }
};
int main()
{
    vector<int> v ={1,2,3,4,5,6,7,8};
    Solution obj;
    vector<int> ans = obj.shuffle(v , 4);
    for(int x : ans)
    {
        cout<<x<<" ";
    }
    return 0;
}