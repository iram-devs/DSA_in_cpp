#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int ans=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1) count++;
            if(nums[i]==0){
                ans=max(ans,count);
                count=0;
            }
        }
        ans=max(ans,count);
        return ans;
    }
};
int main()
{
    vector <int> v = {1,1,1,0,0,1,0,1,1,1,1};
    Solution obj;
    int ans = obj.findMaxConsecutiveOnes(v);
    cout<<ans<<endl;
    return 0;
}