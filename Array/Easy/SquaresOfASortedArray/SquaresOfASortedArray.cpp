#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) 
        {
         vector <int> square;
         for(int i=0;i<nums.size();i++)
         {
           square.push_back(nums[i]*nums[i]);
         }
        sort(square.begin(),square.end());
        return square;
     }
};
int main()
{
    vector<int> nums = {-3,-4,2,5,1,0};
    Solution obj;
    vector<int>ans=obj.sortedSquares(nums);
    for(int x :ans)
    {
        cout<<x<<" ";
    }
    return 0;
}