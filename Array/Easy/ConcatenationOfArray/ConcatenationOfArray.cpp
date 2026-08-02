#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int i = 1;
        vector<int> ans = {};
        while(i<=2)
        {
            for(int x:nums)
            {
                ans.push_back(x);
            }
            i++;
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {1,3,2,1};
    Solution obj;
    vector<int> ans = obj.getConcatenation(nums);
    for(int x : ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0; 
}