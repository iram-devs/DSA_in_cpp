#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i =1;i<=n;i++)
        {
            if(n % i==0)
            {
                ans += (nums[i-1]*nums[i-1]);
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums ={1,2,3,4};
    Solution obj;
    cout<<"ans:"<<obj.sumOfSquares(nums);
    return 0;
}